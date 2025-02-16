#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixedPointNumberValue;				// 고정 소수점 값을 저장할 정수형 변수
		const static int _fractionalBits = 8;	// 소수부 비트의 수를 저장하는 정적 정수형 상수

	public:
		Fixed(); 								// Default Constructor - 고정 소수점 값을 0으로 초기화
		Fixed(const Fixed &src); 				// Copy Constructor
		Fixed& operator=(const Fixed &src); 	// Copy Assignment operator(복사 대입 연산자)
		~Fixed(); 								// Destructor
		
		int getRawBits(void) const; 			// 고정 소수점 값의 원시값을 반환
		void setRawBits(int const raw); 		// 고정 소수점 수의 원시값을 설정
		
};
# endif