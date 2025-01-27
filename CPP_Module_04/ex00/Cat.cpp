#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy dontstructor called" << std::endl;

	*this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat assignation operator called" << std::endl;

	if (this == &cat) return *this;
	type = cat.type;
	return *this;
}

void Cat::makesound() const
{
	std::cout << "냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥" << std::endl;
}