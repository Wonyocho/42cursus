#include <iostream>
#include "PhoneBook.hpp"

int toInt(std::string input);
int GetIndex();
std::string GetText();

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (1) // 무한 루프
	{
		std::cout << "What do you wanna do? ADD/SEARCH/EXIT" << std::endl; // 커맨드 입력하라는 문구
		input = GetText(); // 커맨드 입력받기

		if (input == "EXIT" || input == "exit") // EXIT 입력 시
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
		else if (input == "ADD" || input == "add") // ADD 입력 시
		{
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickName;

			// 각 정보 입력받기
			std::cout << "First name: " << std::endl;
			contact.SetFirstName(GetText()); // 입력받은 정보 저장
			std::cout << "Last name: " << std::endl;
			contact.SetLastName(GetText());
			std::cout << "Nick name: " << std::endl;
			contact.SetNickName(GetText());
			std::cout << "Phone number: " << std::endl;
			contact.SetPhoneNumber(GetText());
			std::cout << "Darkest secret: " << std::endl;
			contact.SetDarkestSecret(GetText());

			phoneBook.Add(contact); // 연락처 추가
		}
		else if (input == "SEARCH" || input == "search") // SEARCH 입력 시
		{
			if (phoneBook.GetSize() == 0) // 연락처가 없을 경우
			{
				std::cout << "No Contacts" << std::endl; // 연락처 없음
				continue;
			}
			else // 연락처가 있을 경우
			{
				phoneBook.Show(); // 연락처 출력
				phoneBook.SelectIndex(GetIndex()); // 인덱스 선택
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
		std::getline(std::cin, text); // 한 줄 입력받기
		if (!text.empty()) // 입력이 있을 경우
		{
			break;
		}
		std::cout << "Invalid input" << std::endl; // 입력이 없을 경우
	}
	return (text);
}

int toInt(std::string input) // 문자열을 정수로 변환
{
	if (input.size() != 1) // 문자열 길이가 1이 아닐 경우
	{
		return (-1);
	}
	if (!isdigit(input[0])) // 숫자가 아닐 경우
	{
		return (-1);
	}
	return (input[0] - '0'); // 문자를 숫자로 변환
}

int GetIndex() // 인덱스 입력받기
{
	int index;

	while (1)
	{
		std::cout << "index ";
		index = toInt(GetText()); // 문자열을 정수로 변환
		if (index < 0 || index > 7) // 인덱스가 0보다 작거나 7보다 클 경우
		{
			std::cout << "Invalid index" << std::endl; // 잘못된 인덱스
		}
		else
		{
			break;
		}
	}
	return (index); // 인덱스 반환
}
