#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> // std::setw 사용하기 위해서
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		// 멤버 함수
		void Add(Contact contact);
		void Show();
		void SelectIndex(int index);
		int GetSize();

    private:
		// 멤버 변수
		Contact contact[8];
		int _size;
};

#endif
