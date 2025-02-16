#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	// N이 0 이하일 경우, 에러 메시지 출력
    if (N <= 0)
    {
        std::cout << "Error: N must be greater than 0" << std::endl;
        return NULL;
    }

	// N 크기의 Zombie 배열 생성
    Zombie* zombieHorde = new Zombie[N];

	// N 크기만큼 이름 설정
    for (int i = 0; i < N; i++)
    {
        zombieHorde[i].getName(name); // 이름 설정
    }
	
    return (zombieHorde);
}
