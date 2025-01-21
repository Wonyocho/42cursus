#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(); // 고정소수점 값을 0으로 초기화 해줄 기본 생성자
		Fixed(const Fixed &src); // 복사 생성자
		Fixed(float const raw);
		Fixed(int const raw);
		Fixed& operator=(const Fixed &src); // 대입연산자 오버로딩

		~Fixed(); // 소멸자
		
		int getRawBits(void) const; // 고정 소수점 값의 원시값을 '반환'
		void setRawBits(int const raw); // 고정 소수점수의 원시값을 '설정'
		int toInt(void) const;
		float toFloat(void) const;
		
	private:
		int _fixedPointValue;
		const static int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);
# endif