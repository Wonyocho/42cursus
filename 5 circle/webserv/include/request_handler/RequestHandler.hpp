#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

#include <string>
#include <iostream>

#include "ServerConfig.hpp"
#include "Kqueue.hpp"
#include "Request.hpp"
#include "Router.hpp"
#include "CgiHandler.hpp"

class RequestHandler {
private:
    Router router_;
    CgiHandler cgiHandler_;
    Request request_;

public:
    RequestHandler(ServerConfig& serverConfig, Request &request, Kqueue& kqueue);
    ~RequestHandler();
    
    void handleRequest(const Request& request, int clientFd);
};

#endif // REQUESTHANDLER_HPP
