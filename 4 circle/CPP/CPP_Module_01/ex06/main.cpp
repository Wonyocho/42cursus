/*
원하는 로그 레벨에 따라 할이 하는 말을 걸러내는 시스템 구현하기.

- 네가지 레벨중 하나를 인자로 받는다. 해당 레벨과 그 이상의 레벨에 해당하는 모든 메시지를 출력한다.
- 스위치를 사용한다.
- 실행파일의 이름을 harlFilter이라고 지정한다.
*/

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return (1);
	}

	Harl harl;
	harl.complain(argv[1]);
	return (0);
}