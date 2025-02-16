#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointNumberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// 상수 부동소수점 숫자를 매개변수로 받는 생성자.
Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumberValue = roundf(raw * (1 << this->_fractionalBits)); // 소수점 이하 자리를 고정 소수점으로 변환.
}

// 상수 정수를 매개변수로 받는 생성자.
Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumberValue = raw << this->_fractionalBits; // 정수를 고정 소수점으로 변환.
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_fixedPointNumberValue = src.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumberValue = raw;
}

// 고정소수점 값을 부동소수점 값으로 변환.
float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumberValue / (1 << this->_fractionalBits));
}

// 고정소수점 값을 정수로 변환.
int Fixed::toInt(void) const
{
	return (this->_fixedPointNumberValue >> this->_fractionalBits);
}

// 매개변수로 전달된 출력 스트림 객체에 '고정'소수점 숫자의 '부동'소수점 표현을 삽입하는 << 연산자 오버로딩.
std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
