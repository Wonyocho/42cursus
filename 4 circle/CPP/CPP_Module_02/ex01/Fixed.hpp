#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixedPointNumberValue;				// 고정 소수점 값을 저장할 정수형 변수.
		const static int _fractionalBits = 8;	// 소수부 비트의 수를 저장하는 정적 정수형 상수.

	public:
		Fixed(); 								// Default Constructor - 고정 소수점 값을 0으로 초기화.
		Fixed(const Fixed &src); 				// Copy Constructor.
		Fixed(const int raw);					// 상수 정수를 매개변수로 받는 생성자.
		Fixed(const float raw);					// 상수 부동소수점 숫자를 매개변수로 받는 생성자.
		Fixed& operator=(const Fixed &src); 	// Copy Assignment operator(복사 대입 연산자).
		~Fixed(); 								// Destructor.
		
		int getRawBits(void) const; 			// 고정소수점 값의 원시값을 반환.
		void setRawBits(int const raw); 		// 고정소수점 수의 원시값을 설정.
		float toFloat(void) const;				// 고정소수점 값을 부동소수점 값으로 변환.
		int toInt(void) const;					// 고정소수점 값을 정수로 변환.
};

// 매개변수로 전달된 출력 스트림 객체에 '고정'소수점 숫자의 '부동'소수점 표현을 삽입하는 << 연산자 오버로딩.
std::ostream& operator<<(std::ostream &out, const Fixed &obj);

# endif