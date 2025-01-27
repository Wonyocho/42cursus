#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brian constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
	if (this == &brain)
	{
		return *this;
	}
	
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = brain.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea)
{
	if (!(0 <= i && i < 100))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}

	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (!(0 <= i && i < 100))
	{
		std::cout << "Invalid index" << std::endl;
		return "";
	}

	return ideas[i];
}