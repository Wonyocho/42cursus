#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Animal assignation operator called" << std::endl;

	if (this == &dog) return *this;
	type = dog.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "멍멍멍멍멍멍멍멍멍멍멍멍멍멍멍" << std::endl;
}