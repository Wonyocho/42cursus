#ifndef WRONGCAT_ANIMAL
#define WRONGCAT_ANIMAL

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& wrongAnimal);
		WrongAnimal& operator=(const WrongAnimal& wrongAnimal);

		std::string getType() const;
		void makeSound() const;
};

#endif