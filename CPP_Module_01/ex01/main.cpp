#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	
	// N 크기의 Zombie 배열 생성
	Zombie *horde = zombieHorde(N, "woonshin");

	// N 크기만큼 announce 함수 호출
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	
	delete [] horde; // 배열을 삭제할 때는 []를 붙여야 한다.

	return (0);
}