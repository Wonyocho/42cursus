#include "ConfigParser.hpp"

void ConfigParser::Tokenize(std::string config_data)
{
	std::stringstream configStream(config_data);
	std::string currentToken; // 현재 처리중인 토큰

	while (configStream >> currentToken)
	{
		configTokens_.push_back(currentToken);
	}
}

IConfigContext* ConfigParser::Parser()
{
	IConfigContext *root = new IConfigContext(NULL, MAIN);
	
	try
	{
		ParserRecursive(configTokens_, root);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		DeleteTree(root);
		return NULL;
	}

	return root;
}

void ConfigParser::ParserRecursive(std::vector<std::string> configTokens, IConfigContext* parentContext)
{
	// iterator 설정.
	std::vector<std::string>::iterator currentIter = configTokens.begin();
	std::vector<std::string>::iterator lastIter = configTokens.end();
	lastIter--;

	// 예외 처리.
	if (currentIter == lastIter) throw (ConfigParser::ConfigSyntaxError());

	// 파싱 시작.
	while (currentIter != configTokens.end())
	{
		// 1. 현재 토큰이 Context / Directive 인지 확인.
		int contextType = IsContext(*currentIter);
		int directiveType = IsDirective(*currentIter);

		// 2. Context 인 경우.
		if (contextType != -1 && directiveType == -1)
		{
			// 다음 토큰이 없는 경우 예외 처리.
			if (currentIter == lastIter) throw ConfigParser::ConfigSyntaxError();
			++currentIter; // 다음 토큰으로 이동. ('/' or '{' 를 가리키게 됨.)

			// 새로운 Context 노드 생성.
			IConfigContext* newContextNode = new IConfigContext(parentContext, contextType);

			// Context 옵션 추가. (없을시 실행 안됨.)
			while ((currentIter != configTokens.end()) && (*currentIter != "{"))
			{
				newContextNode->AddOptions(*currentIter);
				++currentIter;
			}
			// 예외 처리.
			if (currentIter == configTokens.end()) throw ConfigParser::ConfigSyntaxError();

			// Context 중괄호 내부 파싱.
			int BracketCount = 1;
			std::vector<std::string> BracketTokens;
			while (currentIter != configTokens.end())
			{
				++currentIter; // 중괄호 이후의 토큰으로 이동.
				if (currentIter == configTokens.end()) throw ConfigParser::ConfigSyntaxError();
				if (*currentIter == "{") BracketCount++;
				if (*currentIter == "}") BracketCount--;
				if (BracketCount == 0) break;
				BracketTokens.push_back(*currentIter);
			}
			if (BracketCount != 0) throw ConfigParser::ConfigSyntaxError();

			// 재귀적으로 파싱.
			try
			{
				ParserRecursive(BracketTokens, newContextNode);
			}
			catch(...)
			{
				throw ConfigParser::ConfigSyntaxError();
			}
		}
		// 3. Directive 인 경우.
		else if (directiveType != -1 && contextType == -1)
		{
			// 예외 처리.
			if (currentIter == lastIter) throw ConfigParser::ConfigSyntaxError();
			
			std::string DirectiveString = *currentIter; // Directive 이름 저장. ex) "listen"
			IConfigDirective *directive = new IConfigDirective(parentContext, directiveType);
			++currentIter; // ex) "80;"

			// Directive 값 추가.
			while ((currentIter != configTokens.end()) && (*currentIter != ";"))
			{
				std::string::iterator TokenIterEnd = currentIter->end();
				--TokenIterEnd;
				if (*TokenIterEnd == ';')
				{
					directive->AddValue(currentIter->substr(0, currentIter->size() - 1)); // ';' 제거하고 추가.
					break;
				}
				directive->AddValue(*currentIter);
				++currentIter;
			}

			// parentContext에 directive 추가.
			parentContext->AddDirectives(directive);
		}
		// 4. 그 외의 경우.
		else if (directiveType == -1 && contextType == -1) 
		{
			throw ConfigParser::ConfigSyntaxError();
		}
	}
}

const char* ConfigParser::ConfigSyntaxError::what() const throw()
{
	return ("Error: Config file has Syntax Error");
}
