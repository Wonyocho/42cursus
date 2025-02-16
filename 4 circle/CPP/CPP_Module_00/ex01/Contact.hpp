#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();

        // Setter
        void SetFirstName(std::string firstName);
        void SetLastName(std::string lastName);
        void SetNickName(std::string nickName);
        void SetPhoneNumber(std::string phoneNumber);
        void SetDarkestSecret(std::string darkestSecret);
        void SetAllContact(Contact contact);

        // Getter
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();

    private:
        // Contact Information
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

#endif