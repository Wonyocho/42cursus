#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// #include "Fixed.hpp"
// #include <iostream>

// int main() {
//     // 1. 기본 생성자, 정수 생성자, 부동소수점 생성자 사용
//     Fixed a;                // 기본 생성자 호출
//     Fixed b(10);            // 정수 생성자 호출
//     Fixed c(42.42f);        // 부동소수점 생성자 호출
//     Fixed d(b);             // 복사 생성자 호출

//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "2. 복사 대입 연산자 사용" << std::endl;
//     a = Fixed(123.456f);    // 복사 대입 연산자 호출

//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "3. 출력 연산자 (<<) 오버로딩 사용" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "d: " << d << std::endl;

//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "4. 비교 연산자 사용" << std::endl;
//     std::cout << "b < c: " << (b < c) << std::endl;
//     std::cout << "b <= c: " << (b <= c) << std::endl;
//     std::cout << "b > c: " << (b > c) << std::endl;
//     std::cout << "b >= c: " << (b >= c) << std::endl;
//     std::cout << "b == d: " << (b == d) << std::endl;
//     std::cout << "b != c: " << (b != c) << std::endl;

//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "5. 산술 연산자 사용" << std::endl;
//     Fixed e = b + c;        // 덧셈 연산
//     Fixed f = c - b;        // 뺄셈 연산
//     Fixed g = b * c;        // 곱셈 연산
//     Fixed h = c / b;        // 나눗셈 연산

//     std::cout << "e (b + c): " << e << std::endl;
//     std::cout << "f (c - b): " << f << std::endl;
//     std::cout << "g (b * c): " << g << std::endl;
//     std::cout << "h (c / b): " << h << std::endl;


//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "6. 증감 연산자 사용" << std::endl;
//     std::cout << "a (before increment): " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;    // 전위 증가
//     std::cout << "a++: " << a++ << std::endl;    // 후위 증가
//     std::cout << "a (after increment): " << a << std::endl;

//     std::cout << "--a: " << --a << std::endl;    // 전위 감소
//     std::cout << "a--: " << a-- << std::endl;    // 후위 감소
//     std::cout << "a (after decrement): " << a << std::endl;

//     std::cout << "\n*******************************\n" << std::endl;
//     std::cout << "7. 정적 min/max 함수 사용" << std::endl;
//     Fixed const x(3.14f);
//     Fixed const y(2.71f);

//     std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
//     std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

//     return 0;
// }
