#pragma once

#include "Request.hpp"
#include "Kqueue.hpp"
#include "CGIExecuter.hpp"

class CGIHandler
{
	private:
	
	public:
		CGIHandler();
		~CGIHandler();
		
		void CGIHandler::handleRequest(const Request& request, Kqueue& kqueue);
};