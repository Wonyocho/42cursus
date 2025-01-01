/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:46:12 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 14:15:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
		}
	}
    return true;
}

void show_pages(PhoneBook page[8])
{
    for(int i = 0; i < 8; i++) {
        page[i].print_page();
    }
}

void show_privew(PhoneBook page[8])
{
	std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nick Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Cell Phone";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Secret";
    std::cout << std::endl;
    
    for(int i = 0; i < 8; i++) {
        page[i].print_privew(i);
    }
}

void select_index(PhoneBook page[8])
{
    int select_index;
    std::string input_index;
    std::stringstream ss; // 문자열을 숫자로 변환하기 위한 스트림

    std::cout << "Select index : ";
    std::getline(std::cin, input_index);
    ss << input_index;
    ss >> select_index; // 문자열을 숫자로 변환
    
    if (0 <= select_index && select_index <= 8 && ss.fail() == false)
        page[select_index].print_page();
    else
        std::cout << "This is an unauthorized number." << std::endl;
}
