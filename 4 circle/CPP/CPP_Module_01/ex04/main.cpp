/*
	1. 순서대로 세개의 인자 `filename`, and two strings `s1`, `s2` 를 받는다
	2. 프로그램은 filename을 열고, 파일 내용을 <filename>.replace라는 새 파일에 복사한다.
    	1. 이때, 모든 s1을 s2로 대체한다.
*/

#include <iostream>
#include <string>
#include <fstream>

// 대체 함수
void do_replace(std::ofstream &outfile, const std::string line, const std::string s1, const std::string s2)
{
	std::string modifiedLine; // 대체된 문자열 저장
	size_t start = 0;	// 시작 위치
	size_t pos = 0;		// 위치
	
	// s1을 s2로 대체
	while ((pos = line.find(s1, start)) != std::string::npos) // s1을 찾을 때까지 반복 (std::string::npos는 문자열의 끝을 의미)
	{
		modifiedLine += line.substr(start, pos - start); // s1 이전 문자열 추가
		modifiedLine += s2; // s2 추가
		start = pos + s1.length(); // s1 다음 위치로 이동
	}
	modifiedLine += line.substr(start); // s1 이후 문자열 추가
	outfile << modifiedLine << std::endl; // 대체된 문자열 파일에 쓰기
}

// 입력값 확인 함수
bool isValidArguments(int argc, char **argv)
{
	// 1. 인자가 4개가 아니면 false 반환
	if (argc != 4)
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		return (false);
	}

	// 2. 인자가 4개인데, 두번째, 세번째, 네번째 인자 중 하나라도 비어있으면 false 반환
	if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	// 입력값 확인
	if (!isValidArguments(argc, argv))
	{
		return (1);
	}

	std::string filename = argv[1]; // 파일 이름
	std::string replaceFilename = filename + ".replace"; // 대체 파일 이름
	std::string s1 = argv[2]; // 대체할 문자열
	std::string s2 = argv[3]; // 대체될 문자열

	// 1. 파일 열기
	// ifstream : 파일 입력 스트림 클래스
	std::ifstream infile(filename.c_str()); // c_str() : C 스타일 문자열로 변환. 널종료 문자열 반환
	if (!infile.is_open()) // 파일 열기 실패
	{
		std::cout << "Error: File open failed" << std::endl;
		return (1);
	}

	// 2. 대체 파일 열기
	std::ofstream outfile(replaceFilename.c_str());
	if (!outfile.is_open()) // 대체 파일 열기 실패
	{
		std::cout << "Error: File open failed" << std::endl;
		return (1);
	}
	
	// 3. 파일 읽기
	std::string line;
	while (std::getline(infile, line)) // 파일 끝까지 읽기
	{
		do_replace(outfile, line, s1, s2); // 대체
	}

	// 4. 파일 닫기
	if (infile.bad())
	{
		std::cout << "Error: File read failed" << std::endl;
		return (1);
	}

	std::cout << "File replace success" << std::endl; // 대체 성공
	return (0);
}
