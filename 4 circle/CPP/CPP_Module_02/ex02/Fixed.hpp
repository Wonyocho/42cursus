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

		// 비교 연산자 6개 오버로딩.
		bool operator<(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator>(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;

		// 산술 연산자 4개 오버로딩.
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		// 증감 연산자 4개 오버로딩.(전위, 후위)
		Fixed &operator++(void);			// 전위 증가 연산자.
		const Fixed operator++(int);		// 후위 증가 연산자.
		Fixed &operator--(void);			// 전위 감소 연산자.
		const Fixed operator--(int);		// 후위 감소 연산자.

		// 정적 함수 4개 선언.
		static Fixed &min(Fixed &left, Fixed &right);					// 고정-소수점 숫자에 대한 두 개의 참조를 매개변수로 받아 가장 작은 것에 대한 참조를 반환
		static const Fixed &min(Fixed const &left, Fixed const &right);	// 상수 고정-소수점 숫자에 대한 두 개의 참조를 매개변수로 받아 가장 작은 것에 대한 참조를 반환
		static Fixed &max(Fixed &left, Fixed &right);					// 고정-소수점 숫자에 대한 두 개의 참조를 매개변수로 받아 가장 큰 것에 대한 참조를 반환
		static const Fixed &max(Fixed const &left, Fixed const &right);	// 상수 고정-소수점 숫자에 대한 두 개의 참조를 매개변수로 받아 가장 큰 것에 대한 참조를 반환
		
};

// 매개변수로 전달된 출력 스트림 객체에 '고정'소수점 숫자의 '부동'소수점 표현을 삽입하는 << 연산자 오버로딩.
std::ostream& operator<<(std::ostream &out, const Fixed &obj);
# endif