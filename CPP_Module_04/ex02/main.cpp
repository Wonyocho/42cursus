#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[10];

    // Animal 배열에 Dog와 Cat 객체 추가
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Animal 배열을 순회하며 소리 출력
    for (int i = 0; i < 10; i++) {
        animals[i]->makeSound();
        delete animals[i]; // 메모리 해제
    }

    std::cout << std::endl << "---------------------------" << std::endl;

    // Dog 객체 복사 테스트
    const Dog* dog = new Dog();
    const Dog* copiedDog = new Dog(*dog);

    dog->getBrain()->setIdea(0, "*** Original Dog Idea ***");
    copiedDog->getBrain()->setIdea(0, "*** Copied Dog Idea ***");

    std::cout << "*** Dog's Brain: ***" << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "*** Copied Dog's Brain: ***" << copiedDog->getBrain()->getIdea(0) << std::endl;

    delete dog;
    delete copiedDog;

    return 0;
}
