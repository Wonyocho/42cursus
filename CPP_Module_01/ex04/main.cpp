/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:18:56 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 16:18:18 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/*
	1. 순서대로 세개의 인자 `filename`, and two strings `s1`, `s2` 를 받는다
	2. 프로그램은 filename을 열고, 파일 내용을 <filename>.replace라는 새 파일에 복사한다.
    	1. 이때, 모든 s1을 s2로 대체한다.
*/

void do_replace(std::ofstream &outfile, const std::string line, const std::string s1, const std::string s2)
{
	std::string modifiedLine;
	size_t start = 0;
	size_t pos = 0;
	
	while ((pos = line.find(s1, start)) != std::string::npos)
	{
		modifiedLine += line.substr(start, pos - start);
		modifiedLine += s2;
		start = pos + s1.length();
	}
	modifiedLine += line.substr(start);
	outfile << modifiedLine << std::endl;
}

bool isValidArguments(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		return (false);
	}
	if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (!isValidArguments(argc, argv))
	{
		return (1);
	}

	std::string filename = argv[1];
	std::string replaceFilename = filename + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: File open failed" << std::endl;
		return (1);
	}

	std::ofstream outfile(replaceFilename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: File open failed" << std::endl;
		return (1);
	}
	
	std::string line;
	while (std::getline(infile, line))
	{
		do_replace(outfile, line, s1, s2);
	}

	if (infile.bad())
	{
		std::cout << "Error: File read failed" << std::endl;
		return (1);
	}

	std::cout << "File replace success" << std::endl;
	return (0);
}
