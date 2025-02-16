#include "FragTrap.hpp"

int main(void) {
	FragTrap fragTrap("리자몽");
	FragTrap fragTrap2(fragTrap);

	fragTrap.attack("이상해씨");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();

	for (int i = 0; i < 10; i++) {
		fragTrap2.attack("이상해씨");
	}

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Energy: " << fragTrap2.getEnergyPoints() << std::endl;
	fragTrap2.beRepaired(5);
	fragTrap2.highFivesGuys();

	return 0;
}