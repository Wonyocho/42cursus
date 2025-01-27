#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;

	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;

	delete brain;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	
	brain = new Brain(*dog.brain);
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog assignation operator called" << std::endl;

	if (this == &dog) return *this;

	type = dog.type;
	if (brain) delete brain;
	brain = new Brain(*dog.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << " *** 멍멍멍 *** " << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}