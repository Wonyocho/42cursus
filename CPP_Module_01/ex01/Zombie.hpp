#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie();                    // 기본 생성자
        ~Zombie();                   // 소멸자

        void announce(void) const;   // announce 함수
        void getName(std::string name); // 이름 설정 함수

    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
