#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;

	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;

	delete brain;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	
	brain = new Brain(*cat.brain);
	*this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat assignation called" << std::endl;

	if (this == &cat) return *this;

	type = cat.type;
	if (brain) delete brain;
	brain = new Brain(*cat.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << " *** 냥냥냥 *** " << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}
