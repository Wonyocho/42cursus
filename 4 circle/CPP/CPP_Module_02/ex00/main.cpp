#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;	// 기본 생성자를 사용해 객체 a 생성
	Fixed b(a);	// 복사 생성자를 사용해 객체 b 생성(b를 a로 초기화)
	Fixed c;	// 기본 생성자를 사용해 객체 c 생성

	c = b; 		// 복사 대입 연산자를 사용해 c에 b를 대입

	// getRawBits() 함수를 사용해 객체의 고정 소수점 값을 출력
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// a.setRawBits(42);
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;

	return 0;
}
