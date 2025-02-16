/*
1. HI THIS IS BRAIN으로 초기화된 문자열 변수
2. `stringPTR`: 문자열을 가리키는 포인터
3. `stringREF`: 문자열을 참조하는 참조자

다음을 출력해야한다.
1. 문자열 변수의 메모리 주소
2. `stringPTR`이 가리키는 메모리 주소
3. `stringREF`가 가리키는 메모리 주소
4. 문자열 변수의 값
5. `stringPTR`이 가리키는 값
6. `stringREF`가 가리키는 값
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";	// 문자열 변수
	std::string *stringPTR = &str;			// 문자열을 가리키는 포인터
	std::string &stringREF = str;			// 문자열을 참조하는 참조자
	
	std::cout << "str address : " << &str << std::endl; // 문자열 변수의 메모리 주소
	std::cout << "stringPTR address : " << stringPTR << std::endl; // `stringPTR`이 가리키는 메모리 주소
	std::cout << "stringREF address : " << &stringREF << std::endl; // `stringREF`가 가리키는 메모리 주소
	std::cout << "str value : " << str << std::endl; // 문자열 변수의 값
	std::cout << "stringPTR value : " << *stringPTR << std::endl; // `stringPTR`이 가리키는 값
	std::cout << "stringREF value : " << stringREF << std::endl; // `stringREF`가 가리키는 값
	
	return (0);	
}
