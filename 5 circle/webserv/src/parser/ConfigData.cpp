#include "ConfigData.hpp"

ConfigData::ConfigData() {}

ConfigData::ConfigData(IConfigContext *contextRoot)
{
	if (!contextRoot) throw (ConfigData::ConfigSyntaxError());
	dataRoot_ = contextRoot;
}

ConfigData::~ConfigData()
{
	DeleteTree(dataRoot_);
}

IConfigContext* ConfigData::getRoot()
{
	return (dataRoot_);
}

void ConfigData::PrintData(IConfigContext *parent)
{
	std::vector<IConfigContext *> childs = parent->getChild();
	for (size_t i = 0; i < childs.size(); ++i)
	{
		PrintData(childs[i]);
	}
	std::cout << "========================================\n\n"
	<< "Child Data\n"
	<< "Type: " << parent->getType() << "\n"
	<< "Options: ";
	std::vector<std::string> options = parent->getOptions();
	for (size_t i = 0; i < options.size(); ++i)
	{
		std::cout << options[i] << " ";
	}
	std::cout << std::endl;
	std::vector<IConfigDirective *> directives = parent->getDirectives();
	std::cout << "Directive count: " << directives.size() << std::endl;
	std::cout << "-----------------Directives-----------------\n";
	for (size_t i = 0; i < directives.size(); ++i)
	{
		std::cout << i + 1 << " Directive\n" << "Directive Type: " << directives[i]->getType() << std::endl;
		std::vector<std::string> tokens = directives[i]->getValues();
		std::cout << "Tokens: ";
		for (size_t j = 0; j < tokens.size(); ++j)
		{
			std::cout << tokens[j] << " ";
		}
		std::cout << std::endl; 
	}
	std::cout << "-----------------Directives End-----------------\n";
}

const char* ConfigData::ConfigSyntaxError::what() const throw()
{
	return ("Syntax Error in Config File");
}
