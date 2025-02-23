#include "ConfigAdapter.hpp"
#include <iostream>

ConfigAdapter::ConfigAdapter(const std::string &filepath)
    : filepath_(filepath), configData_(nullptr) {}

ConfigAdapter::~ConfigAdapter()
{
    delete configData_;
}

bool ConfigAdapter::loadConfig()
{
    // 1. 파일 읽기
    std::string configContent = reader_.ReadFile(filepath_);
    if (configContent.empty())
	{
        std::cerr << "Failed to read config file." << std::endl;
        return false;
    }

    // 2. 토큰화
    parser_.Tokenize(configContent);

    // 3. 파싱 및 데이터 생성
    IConfigContext *parsedData = parser_.Parser();
    if (!parsedData)
	{
        std::cerr << "Failed to parse config data." << std::endl;
        return false;
    }

    // 4. ConfigData 객체 생성
    configData_ = new ConfigData(parsedData);
    return true;
}

void ConfigAdapter::printConfig() {
    if (configData_)
	{
        configData_->PrintData(configData_->getRoot());
    }
	else
	{
        std::cerr << "Config data is not loaded." << std::endl;
    }
}
