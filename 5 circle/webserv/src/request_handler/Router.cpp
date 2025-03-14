#include "Router.hpp"

Router::Router(const std::string& configFile) {
    loadConfigRoute(configFile);
}

Router::~Router() {}

void Router::addRoute(const std::string& path, const std::string& root) {
    routes_[path] = root;
}

std::string Router::getRootPath(const std::string& path) {
    std::map<std::string, std::string>::iterator it = routes_.find(path);
    if (it != routes_.end()) {
        return it->second;
    }
    return "UNKNOWN";
}

void Router::loadConfigRoute(const std::string& configFile) {
    std::ifstream file(configFile);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open config file: " << configFile << std::endl;
        return;
    }

    std::string line;
    std::string currentLocation;
    std::string currentRoot;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;

        if (key == "location") {
            if (!currentLocation.empty()) {
                addRoute(currentLocation, currentRoot);
            }
            iss >> currentLocation;
            currentRoot = "";
        } else if (key == "root") {
            iss >> currentRoot;
            if (!currentRoot.empty() && currentRoot[currentRoot.size() - 1] == ';') {
                currentRoot = currentRoot.substr(0, currentRoot.size() - 1);
            }
        }
    }

    if (!currentLocation.empty()) {
        addRoute(currentLocation, currentRoot);
    }

    file.close();
}
