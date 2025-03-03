#include "CGIHandler.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sstream>

CGIHandler::CGIHandler() {}

CGIHandler::~CGIHandler() {}

void CGIHandler::setEnvVariables(
	const std::string& scriptPath,
	const std::string& queryString,
	const std::string& requestMethod,
	const std::string& requestBody
)
{
	setenv("PATH_INFO", scriptPath.c_str(), 1);
	setenv("QUERY_STRING", queryString.c_str(), 1);
	setenv("REQUEST_METHOD", requestMethod.c_str(), 1);
	setenv("CONTENT_LENGTH", std::to_string(requestBody.size()).c_str(), 1);
}

std::string CGIHandler::executeCGIScript(
	const std::string& scriptPath,
	const std::string& queryString,
	const std::string& requestMethod,
	const std::string& requestBody
)
{
	int pipefd[2]; // 부모-자식 프로세스간 통신을 위한 데이터 채널.(pipefd[0]: read용 FD, [1]: write용 FD)

	if (pipe(pipefd) == -1) return "Todo: 에러메세지 추가예정";

	pid_t pid = fork(); // 현재 프로세스 복제, 새로운 프로세스를 생성.
	if (pid == -1) 	return "Todo: 에러메세지 추가예정";

	if (pid == 0) // 자식 프로세스(CGI 프로그램 실행)
	{
		close(pipefd[0]); // 자식프로세스는 데이터를 읽지 않고 부모에게 전달하는 역할이므로, 읽기엔드를 닫고 쓰기엔드만 사용하도록 설정.
		dup2(pipefd[1], STDOUT_FILENO); // CGI 출력을 부모 프로세스로 전달.
		close(pipefd[1]); // 필요 없는 파일 디스크립터를 닫아 메모리 낭비 방지.
		setEnvVariables(scriptPath, queryString, requestMethod, requestBody); // 환경변수 설정.

		// POST 요청 본문을 CGI에 전달.
		if (requestMethod == "POST")
		{
			int inputPipe[2]; // POST 데이터 전송을 위한 새로운 파이프.
			if (pipe(inputPipe) == -1) exit(1); // 파이프 생성 실패.

			write(inputPipe[1], requestBody.c_str(), requestBody.size()); // 데이터를 쓰기 엔드에 씀.
			close(inputPipe[1]); // 쓰기 엔드를 닫아 메모리 누수 방지.

			dup2(inputPipe[0], STDIN_FILENO); // CGI 프로그램이 STDIN에서 데이터 읽도록 설정.(Python의 sys.stdin.read()로 데이터를 읽으면, POST 요청 본문이 전달됨.)
			close(inputPipe[0]); // 사용이 끝난 FD 닫기.
		}
		execlp("python3", "python3", scriptPath.c_str(), NULL); // CGI 프로그램 실행.
		exit(1); // execlp가 성공하면 실행안함.
	}
	else // pid > 0: 부모 프로세스(웹서버, CGI 응답 처리)
	{
		close(pipefd[1]); // write close. 부모 프로세스는 읽기만 수행. 닫지 않으면 파이프가 EOF신호를 보내지 않아 read()가 무한 대기 상태가 될 수 있음.
		char buffer[1024];
		std::string response;
		ssize_t bytesRead;

		// CGI 프로그램의 출력을 읽는다.
		while ((bytesRead == read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) // -1: 마지막 바이트는 '\0'.
		{
			buffer[bytesRead] = '\0';
			response += buffer;
		}

		close(pipefd[0]);
		waitpid(pid, NULL, 0); // 자식프로세스 종료 대기.

		return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" + response;
	}
}