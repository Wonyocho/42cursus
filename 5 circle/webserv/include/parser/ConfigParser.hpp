#pragma once

#include "IConfigContext.hpp"
#include "IConfigDirective.hpp"
#include <vector>
#include <sstream>
#include <stdexcept>

class ConfigParser
{
	private:
		std::vector<std::string> configTokens_;
		void ParserRecursive(std::vector<std::string> configTokens, IConfigContext* parentContext);

	public:
		void Tokenize(std::string config_data);
		IConfigContext* Parser();

	class ConfigSyntaxError : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};