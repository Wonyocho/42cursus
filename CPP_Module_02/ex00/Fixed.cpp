#include "Fixed.hpp"

// 기본 생성자
// 고정소수점 값을 0으로 초기화 해줄 기본 생성자
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// 복사 생성자
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// float 타입의 값을 받아서 고정소수점으로 변환하는 생성자
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

// 소멸자
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 고정 소수점 값의 원시값을 '반환'
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// 고정 소수점수의 원시값을 '설정'
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}