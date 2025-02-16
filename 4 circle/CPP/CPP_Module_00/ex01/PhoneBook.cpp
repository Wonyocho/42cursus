#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_size = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::Add(Contact contact) // 연락처 추가
{
	// 연락처가 8개 이상일 경우, 가장 오래된 연락처를 삭제하고 새로운 연락처를 추가
	this->contact[this->_size % 8] = contact;
	_size++;
}

void PhoneBook::Show() // 연락처 출력
{
	// 연락처 출력 양식
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nick name";
	std::cout << "|" << std::endl;

	for (int i = 0; i < this->_size && i < 8; i++) // 최대 8개까지 출력
	{
		// 이름, 성, 닉네임을 각각 저장
		std::string firstName = this->contact[i].GetFirstName();
		std::string lastName = this->contact[i].GetLastName();
		std::string nickName = this->contact[i].GetNickName();

		// 10자 이상일 경우, 9번째 자리에 .으로 대체
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

		// 연락처 출력
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickName << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::SelectIndex(int index) // 인덱스 선택
{
	if (index < 0 || index >= this->_size) // 인덱스가 0보다 작거나 연락처 개수보다 클 경우
	{
		std::cout << "Invalid index" << std::endl; // 잘못된 인덱스
		return ;
	}

	// 선택한 연락처 출력
	std::cout << "First name: " << this->contact[index].GetFirstName() << std::endl;
	std::cout << "Last name: " << this->contact[index].GetLastName() << std::endl;
	std::cout << "Nick name: " << this->contact[index].GetNickName() << std::endl;
	std::cout << "Phone number: " << this->contact[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact[index].GetDarkestSecret() << std::endl;
}

int PhoneBook::GetSize() // 연락처 개수 반환
{
	return this->_size;
}