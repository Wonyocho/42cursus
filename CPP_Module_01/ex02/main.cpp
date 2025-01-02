/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:17 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 14:07:54 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
1. HI THIS IS BRAIN으로 초기화된 문자열 변수
2. `stringPTR`: 문자열을 가리키는 포인터
3. `stringREF`: 문자열을 참조하는 참조자

다음을 출력해야한다
1. 문자열 변수의 메모리 주소
2. `stringPTR`이 가리키는 메모리 주소
3. `stringREF`가 가리키는 메모리 주소
4. 문자열 변수의 값
5. `stringPTR`이 가리키는 값
6. `stringREF`가 가리키는 값
*/

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "str address : " << &str << std::endl;
	std::cout << "stringPTR address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;
	std::cout << "str value : " << str << std::endl;
	std::cout << "stringPTR value : " << *stringPTR << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;
	
	return (0);	
}