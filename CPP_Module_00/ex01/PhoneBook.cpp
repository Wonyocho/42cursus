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
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_size = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add(Contact contact)
{
	this->contact[this->_size % 8] = contact;
	_size++;
}

void PhoneBook::show()
{
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nick name";
	std::cout << "|" << std::endl;

	for (int i = 0; i < this->_size && i < 8; i++)
	{
		std::string firstName = this->contact[i].GetFirstName();
		std::string lastName = this->contact[i].GetLastName();
		std::string nickName = this->contact[i].GetNickName();

		if (firstName.length() > 10)
		{
			firstName.replace(9, firstName.length() - 9, ".");
		}
		if (lastName.length() > 10)
		{
			lastName.replace(9, lastName.length() - 9, ".");
		}
		if (nickName.length() > 10)
		{
			firstName.replace(9, nickName.length() - 9, ".");
		}

		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickName << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::ShowByIndex(int index)
{
	if (index < 0 || index >= this->_size)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}

	std::cout << "First name: " << this->contact[index].GetFirstName() << std::endl;
	std::cout << "Last name: " << this->contact[index].GetLastName() << std::endl;
	std::cout << "Nick name: " << this->contact[index].GetNickName() << std::endl;
	std::cout << "Phone number: " << this->contact[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact[index].GetDarkestSecret() << std::endl;
}

int PhoneBook::getSize()
{
	return this->_size;
}