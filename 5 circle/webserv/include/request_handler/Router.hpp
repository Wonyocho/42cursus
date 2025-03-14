#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class Router {
private:
    Router() {}

    std::map<std::string, std::string> routes_;
    
    void loadConfigRoute(const std::string& configFile);
    void addRoute(const std::string& path, const std::string& root);
    std::string getRootPath(const std::string& path);
    std::string mappedPathJoin(const std::string& root, const std::string& remainingPath);
    

public:
    Router::Router(const std::string& configFile);
    ~Router() {}
};

#endif
