// TODO
// 1. virtual 키워드에 대해
// 2. 복사 대입 연산자 문장은 어떻게 작동하는걸까?
// 3. 왜 Cat, Dog의 복사대입연산자는 this==copy 예외처리를 하지 않을까?
// 4. 이니셜라이저? 관련 공부해보기 어떤건 되고 어떤건 안되고;

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete cat;
	delete dog;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	std::cout << std::endl;

	delete wrongCat;
	return 0;
}