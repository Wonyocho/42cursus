/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:05:01 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/04 13:45:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		bool operator<(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator>(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed &operator++(void);
		const Fixed operator++(int);
		Fixed &operator--(void);
		const Fixed operator--(int);

		static Fixed &min(Fixed &left, Fixed &right);
		static const Fixed &min(Fixed const &left, Fixed const &right);
		static Fixed &max(Fixed &left, Fixed &right);
		static const Fixed &max(Fixed const &left, Fixed const &right);
		
	private:
		int fixedPointValue;
		const static int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);
# endif