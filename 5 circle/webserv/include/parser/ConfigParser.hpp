#pragma once

# include "IConfigContext.hpp"
# include "IConfigDirective.hpp"
# include <vector>
# include <sstream>
# include <stdexcept>

// 설정 파일을 파싱하는 클래스
class ConfigParser
{
	private:
		std::vector<std::string> tokens_; 		// 토큰 벡터
		void ParserRecursive(std::vector<std::string> tokens, IConfigContext *parent); // 재귀 파싱 함수

	public:
		void Tokenize(std::string config_data); // 설정 파일을 토큰화하는 함수
		IConfigContext *Parser();				// 설정 파일을 파싱하는 함수

	
	// 설정 파일 구문 오류 예외 클래스
	class ConfigSyntaxError : public std::exception
	{
		public:
			virtual const char* what() const throw(); // 오류 메시지 반환
	};
};
