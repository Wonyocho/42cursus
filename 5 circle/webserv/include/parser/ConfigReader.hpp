#pragma once

# include <fstream>
# include <iostream>

class ConfigReader
{
	private:
		std::string default_conf_path;					// 기본 설정 파일 경로

	public:
		ConfigReader();									// 생성자
		std::string ReadFile(std::string filepath);		// 파일내용 읽기
		std::string GetDefaultPath();					// 기본 설정 파일 경로 반환
};