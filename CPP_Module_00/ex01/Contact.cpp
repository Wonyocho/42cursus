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

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::GetFirstName()
{
    return this->_firstName;
}

std::string Contact::GetLastName()
{
    return this->_lastName;
}

std::string Contact::GetNickName()
{
    return this->_nickName;
}

std::string Contact::GetPhoneNumber()
{
    return this->_phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
    return this->_darkestSecret;
}





void Contact::SetFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::SetLastName(std::string lastName)
{
    this->_lastName = lastName;
}

void Contact::SetNickName(std::string nickName)
{
    this->_nickName = nickName;
}

void Contact::SetPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string darkestSceret)
{
    this->_darkestSecret = darkestSceret;
}

void Contact::SetAllContact(Contact contact)
{
    this->_firstName = contact.GetFirstName();
    this->_lastName = contact.GetLastName();
    this->_nickName = contact.GetNickName();
    this->_phoneNumber = contact.GetPhoneNumber();
    this->_darkestSecret = contact.GetDarkestSecret();
}