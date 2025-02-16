/*
Todo

1. HARL이라는 클래스를 만든다.
    1. 다음과 같은 `private` 멤버를 만든다.
        - DEBUG 레벨: 디버그 메세지는 상황별 정보를 포함한다. 문제 진단에 사용된다.
        - INFO 레벨: 이 메세지는 광범위한 정보를 포함한다.
        - WARNING 레벨:
        - ERROR 레벨:
    2. public
        - `void complain(std::string level)`

이번 과제의 목표는 멤버 함수 포인터를 사용하는 것이다.

할은 if/else if/else의 무리를 사용하지 않고도 불평을 해야한다.
*/

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		~Harl();

		void complain(std::string level);

	private:
		void Debug();
		void Info();
		void Warning();
		void Error();
};

#endif
