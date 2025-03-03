#pragma once

#include <iostream>
#include <string>
#include "CGIHandler.hpp"

class CGIRequestHandler
{
	public:
		CGIRequestHandler();
		~CGIRequestHandler();

		bool isCGIRequest(const std::string& url);
		std::string handleCGIRequest(const std::string& request, int clientFd);
};