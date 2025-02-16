#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointNumberValue(0) {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(float const raw)
{
	this->_fixedPointNumberValue = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::Fixed(int const raw)
{
	this->_fixedPointNumberValue = raw << this->_fractionalBits;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		this->_fixedPointNumberValue = src.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumberValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumberValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNumberValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

// *************** ex02에서 추가된 부분 *****************

// 비교 연산자 6개 오버로딩.
bool Fixed::operator<(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue < obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue <= obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue > obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue >= obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue != obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->_fixedPointNumberValue == obj.getRawBits());
}

// 산술 연산자 4개 오버로딩.
// 고정 소수점을 부동소수점으로 변환하여 덧셈을 수행하고, 결과를 다시 고정 소수점으로 변환.
Fixed Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

// 고정 소수점을 부동소수점으로 변환하여 뺄셈을 수행하고, 결과를 다시 고정 소수점으로 변환.
Fixed Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

// 고정 소수점을 부동소수점으로 변환하여 곱셈을 수행하고, 결과를 다시 고정 소수점으로 변환.
Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

// 고정 소수점을 부동소수점으로 변환하여 나눗셈을 수행하고, 결과를 다시 고정 소수점으로 변환.
Fixed Fixed::operator/(const Fixed &obj) const
{
	if (obj.getRawBits() == 0) // 나누는 수가 0인 경우 예외 처리.
	{
		throw std::runtime_error("Division by zero");
	}
	return (Fixed(this->toFloat() / obj.toFloat()));
}


// 증감 연산자 4개 오버로딩.(전위, 후위)
// 전위 증가 연산자.
Fixed &Fixed::operator++(void)
{
	this->_fixedPointNumberValue++;
	return (*this);
}
// 후위 증가 연산자.
const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}
// 전위 감소 연산자.
Fixed &Fixed::operator--(void)
{
	this->_fixedPointNumberValue--;
	return (*this);
}
// 후위 감소 연산자.
const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}


// 정적 함수 4개 선언.
Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	return (left < right ? left : right);
}

const Fixed &Fixed::min(Fixed const &left, Fixed const &right)
{
	return (left < right ? left : right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	return (left > right ? left : right);
}

const Fixed &Fixed::max(Fixed const &left, Fixed const &right)
{
	return (left > right ? left : right);
}