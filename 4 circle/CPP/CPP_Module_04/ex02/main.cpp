#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Animal 클래스는 추상 클래스이므로 객체를 생성할 수 없음
    // Animal* animal = new Animal(); // 컴파일 에러 발생

    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->makeSound(); // 출력: Woof! Woof!
    cat->makeSound(); // 출력: Meow! Meow!

    delete dog;
    delete cat;

    return 0;
}
