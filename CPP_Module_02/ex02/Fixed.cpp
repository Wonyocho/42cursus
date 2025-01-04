/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:04:57 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/04 14:07:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(float const raw)
{
	this->fixedPointValue = roundf(raw * (1 << this->fractionalBits));
}

Fixed::Fixed(int const raw)
{
	this->fixedPointValue = raw << this->fractionalBits;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->fixedPointValue < obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->fixedPointValue <= obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->fixedPointValue > obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->fixedPointValue >= obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->fixedPointValue != obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->fixedPointValue == obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	if (obj.getRawBits() == 0) {
		throw std::runtime_error("Division by zero");
	}
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->fixedPointValue++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->fixedPointValue--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

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