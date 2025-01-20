#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	Weapon club1 = Weapon("crude spiked club"); // Weapon 객체 생성
	HumanA bob("Bob", club1); // HumanA 객체 생성
	bob.attack(); // HumanA 객체의 attack() 호출
	club1.setType("some other type of club"); // Weapon 객체의 setType() 호출
	bob.attack(); // HumanA 객체의 attack() 호출
	
	Weapon club2 = Weapon("crude spiked club"); // Weapon 객체 생성
	HumanB jim("Jim"); // HumanB 객체 생성
	jim.setWeapon(club2); // HumanB 객체의 setWeapon() 호출
	jim.attack(); // HumanB 객체의 attack() 호출
	club2.setType("some other type of club"); // Weapon 객체의 setType() 호출
	jim.setWeapon(club2); // HumanB 객체의 setWeapon() 호출
	jim.attack(); // HumanB 객체의 attack() 호출

	return (0);
}