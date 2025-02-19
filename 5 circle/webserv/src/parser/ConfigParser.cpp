#include "ConfigParser.hpp"

// config_data 문자열을 공백을 기준으로 토큰화 -> tokens_ 벡터에 저장.
void ConfigParser::Tokenize(std::string config_data)
{
	std::stringstream ss(config_data);
	std::string token;

	while (ss >> token) // 공백기준으로 토큰에 저장.
	{
		tokens_.push_back(token);
	}
}

IConfigContext* ConfigParser::Parser()
{
	IConfigContext *root = new IConfigContext(NULL, MAIN);

	try
	{
		ParserRecursive(tokens_, root);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		DeleteTree(root);
		return (NULL);
	}
	return (root);
}

void	ConfigParser::ParserRecursive(std::vector<std::string> tokens, IConfigContext *parent)
{
	std::vector<std::string>::iterator it = tokens.begin();		// 토큰의 시작 지점
	std::vector<std::string>::iterator last_it = tokens.end();	// 토큰의 끝 지점

	last_it--;
	if (it == last_it) // 토큰이 하나밖에 없거나, 없는 경우이므로 예외처리.
	{
		throw (ConfigParser::ConfigSyntaxError());
	}

	// 토큰을 확인하며 파싱
	while (it != tokens.end())
	{
		int contextType = IsContext(*it);		// 현재 토큰이 Context인지 확인
		int directiveType = IsDirective(*it);	// 현제 토큰이 Direcrtive인지 확인

		// **************** 컨텍스트인 경우 ****************
		if (contextType != -1 && directiveType == -1)
		{
			// 예외처리 
			if (it == last_it)
			{
				throw (ConfigParser::ConfigSyntaxError());
			}
			++it;

			// 컨텍스트 노드 생성
			IConfigContext* node = new IConfigContext(parent, contextType);
			
			// 컨텍스트 노드의 옵션을 추가.
			while (it != tokens.end() && *it != "{")
			{
				node->AddOptions(*it);
				++it;
			}
			
			// 예외처리
			if (it == tokens.end())
			{
				throw (ConfigParser::ConfigSyntaxError());
			}

			int BracketCount = 1; // 괄호 카운트
			std::vector<std::string> SubTokens;
			
			// 서브 토큰 생성
			while (it != tokens.end())
			{
				++it;
				if (it == tokens.end())
					throw (ConfigParser::ConfigSyntaxError());
				if (*it == "{")
					BracketCount++;
				if (*it == "}")
					BracketCount--;
				if (BracketCount == 0) // 괄호가 닫히면 종료
					break ;
				SubTokens.push_back(*it); // 서브 토큰에 추가
			}
			//*it = }
			// 예외처리
			if (BracketCount != 0) // 괄호가 닫히지 않은 경우
				throw (ConfigParser::ConfigSyntaxError());
			try
			{
				ParserRecursive(SubTokens, node); // 서브 토큰을 재귀적으로 파싱
			}
			catch (...)
			{
				throw (ConfigParser::ConfigSyntaxError());
			}
		}
		// **************** 지시어인 경우 ****************
		else if (directiveType != -1 && contextType == -1)
		{
			if (it == last_it)
				throw (ConfigParser::ConfigSyntaxError());
			std::string DirectiveStr = *it;
			IConfigDirective *directive = new IConfigDirective(parent, directiveType);
			++it;
			while (it != tokens.end() && *it != ";")
			{
				std::string::iterator TokenIterEnd = it->end();
				--TokenIterEnd;
				if (*TokenIterEnd == ';')
				{
					directive->AddValue(it->substr(0, it->size() - 1));
					break ;
				}
				directive->AddValue(*it);
				++it;
			}
			parent->AddDirectives(directive);
		}
		else if (directiveType == -1 && contextType == -1)
		{
			throw (ConfigParser::ConfigSyntaxError());
		}
		++it;
	}
}

// IsContext 함수는 주어진 토큰이 컨텍스트인지 확인하고, 맞다면 해당 인덱스를 반환합니다.
int IsContext(std::string token)
{
	std::vector<std::string> ContextStrings;
	ContextStrings.push_back("main");
	ContextStrings.push_back("http");
	ContextStrings.push_back("server");
	ContextStrings.push_back("events");
	ContextStrings.push_back("location");

	for (size_t i = 0; i < ContextStrings.size(); ++i)
	{
		if (token == ContextStrings[i])
			return (i);
	}
	return (-1);
}

// IConfigContext 클래스의 AddOptions 함수는 옵션을 추가합니다.
void IConfigContext::AddOptions(std::string token)
{
	options_.push_back(token);
}

// ConfigSyntaxError 클래스의 what 함수는 예외 메시지를 반환합니다.
const char* ConfigParser::ConfigSyntaxError::what() const throw()
{
	return ("Error: Config file has syntax error");
}
