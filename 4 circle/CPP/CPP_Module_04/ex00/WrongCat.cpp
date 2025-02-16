#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;

	*this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	
	if (this == &wrongCat) return *this;
	type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "꽥꽥" << std::endl;
}