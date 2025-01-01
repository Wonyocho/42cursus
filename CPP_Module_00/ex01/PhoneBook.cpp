/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:35:38 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 14:18:31 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void PhoneBook::input_contact(int idx)
{
	_idx = idx;

	std::cout << "First name : ";
	std::getline(std::cin, _first_name);
	std::cout << "Last name : ";
	std::getline(std::cin, _last_name);
	std::cout << "Nick name : ";
	std::getline(std::cin, _nick_name);
	std::cout << "Phone number : ";
	std::getline(std::cin, _phone_number);
	std::cout << "darkest secret : ";
	std::getline(std::cin, _darkest_secret);
}

void PhoneBook::print_page(void) const
{
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nick name : " << _nick_name << std::endl;
	std::cout << "Phone number : " << _phone_number << std::endl;
	std::cout << "Darkest secret : " << _darkest_secret << std::endl;
}

void PhoneBook::print_column(std::string _text) const
{
    if (_text.length() <= 10) {
        std::cout << std::right << std::setw(10) << _text;
	} else {
		_text = _text.substr(0,9) + ".";
        std::cout << std::right << std::setw(10) << _text;
    }
}

void PhoneBook::print_privew(int _index) const
{
    print_column(std::to_string(_index));
    std::cout << "|";
    print_column(_first_name);
    std::cout << "|";
    print_column(_last_name);
    std::cout << "|";
    print_column(_nick_name);
    std::cout << "|";
    print_column(_phone_number);
    std::cout << "|";
    print_column(_darkest_secret);
    std::cout << std::endl;
}
