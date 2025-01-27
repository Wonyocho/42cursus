#ifndef BRAIN_HPP
#define BRIAN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		~Brain();
		Brain(const Brain& brain);
		Brain &operator=(const Brain& brain);

		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

#endif