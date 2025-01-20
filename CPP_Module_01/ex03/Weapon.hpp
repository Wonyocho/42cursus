/*
1. `Weapon` 클래스 구현
    1. `private`속성 문자열 `type`
    2. `type`의 상수 참조를 반환하는 `getType()` 멤버함수
    3. 매개변수로 전달된 새로운 `type`을 사용하여 `type`을 설정하는 `setType()` 멤버함수
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(std::string type); // 생성자

		const std::string& getType(void) const; // type의 상수 참조를 반환하는 멤버함수
		void setType(const std::string type); // 매개변수로 전달된 새로운 type을 사용하여 type을 설정하는 멤버함수

	private:
		std::string _type;
};

#endif