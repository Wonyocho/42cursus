#pragma once

#include <iostream>
#include <string>
#include <map>

class CGIHandler
{
	private:
		// CGI 실행전 환경변수 설정.
		void setEnvVariables(
			const std::string& scriptPath,
			const std::string& queryString,
			const std::string& requestMethod,
			const std::string& requestBody
		);

	public:
		CGIHandler();
		~CGIHandler();
		
		// CGI 스크립트를 실행하고 응답을 반환.
		std::string executeCGIScript(
			const std::string& scriptPath,
			const std::string& queryString,
			const std::string& requestMethod,
			const std::string& requestBody
		);
};