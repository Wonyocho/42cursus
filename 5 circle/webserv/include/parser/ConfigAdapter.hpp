#pragma once

#include "ConfigReader.hpp"
#include "ConfigParser.hpp"
#include "ConfigData.hpp"

class ConfigAdapter
{	
	private:
		ConfigReader reader_;
		ConfigParser parser_;
		ConfigData *configData_;
		std::string filepath_;
		
	public:
		ConfigAdapter(const std::string &filepath);
		~ConfigAdapter();

		bool loadConfig();
		void printConfig();
};
