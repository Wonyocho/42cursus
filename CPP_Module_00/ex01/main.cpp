/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:31:24 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 14:20:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int ParseInt(std::string input);
int GetIndex();
std::string GetText();

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (1)
	{
		std::cout << "What do you wanna do? ADD/SEARCH/EXIT" << std::endl; // 커맨드 입력하라는 문구
		input = GetText(); // 커맨드 입력받기

		if (input == "EXIT" || input == "exit")
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
		else if (input == "ADD" || input == "add")
		{
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickName;

			std::cout << "First name: " << std::endl;
			contact.SetFirstName(GetText());
			std::cout << "Last name: " << std::endl;
			contact.SetLastName(GetText());
			std::cout << "Nick name: " << std::endl;
			contact.SetNickName(GetText());
			std::cout << "Phone number: " << std::endl;
			contact.SetPhoneNumber(GetText());
			std::cout << "Darkest secret: " << std::endl;
			contact.SetDarkestSecret(GetText());

			phoneBook.add(contact);
		}
		else if (input == "SEARCH" || input == "search")
		{
			if (0 == phoneBook.getSize())
			{
				std::cout << "No Contacts" << std::endl;
				continue;
			}
			else
			{
				phoneBook.show();
				phoneBook.ShowByIndex(GetIndex());
			}
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}

std::string GetText()
{
	std::string text;

	while(1)
	{
		std::cout << "> ";
		std::getline(std::cin, text);
		if (!text.empty())
		{
			break;
		}
		std::cout << "Invalid input" << std::endl;
	}
	return (text);
}

int ParseInt(std::string input)
{
	if (input.size() != 1)
	{
		return (-1);
	}
	if (!isdigit(input[0]))
	{
		return (-1);
	}
	return (input[0] - '0');
}

int GetIndex()
{
	int index;

	while (1)
	{
		std::cout << "index ";
		index = ParseInt(GetText());
		if (index < 0 || index > 7)
		{
			std::cout << "Invalid index" << std::endl;
		}
		else
		{
			break;
		}
	}
	return (index);
}
