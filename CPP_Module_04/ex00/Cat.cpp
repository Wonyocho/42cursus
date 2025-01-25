#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
	type = cat.type;
	return *this;
}

void Cat::makesound() const
{
	std::cout << "냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥냥" << std::endl;
}