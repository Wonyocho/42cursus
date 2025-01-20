#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::Debug()
{
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::Info()
{
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::Warning()
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::Error()
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

// complain 함수는 level에 따라 Debug, Info, Warning, Error 함수를 호출한다.
void Harl::complain(std::string level)
{
	std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error};


	// level에 따라 함수 호출
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (type[i] == level)
		{
			break ;
		}
	}
	// switch문을 사용하여 함수 호출
	switch (i)
	{
		case 0:
			(this->*func[0])();
			std::cout << std::endl;
		case 1:
			(this->*func[1])();
			std::cout << std::endl;
		case 2:
			(this->*func[2])();
			std::cout << std::endl;
		case 3:
			(this->*func[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
