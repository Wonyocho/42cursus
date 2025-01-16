/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:46:55 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 11:49:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();

        void SetFirstName(std::string firstName);
        void SetLastName(std::string lastName);
        void SetNickName(std::string nickName);
        void SetPhoneNumber(std::string phoneNumber);
        void SetDarkestSecret(std::string darkestSecret);
        void SetAllContact(Contact contact);

        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

#endif