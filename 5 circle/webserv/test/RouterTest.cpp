#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class Router {
private:
    std::map<std::string, std::string> routes_;  // 요청 경로 -> 실제 경로 매핑

public:
    Router() {}
    ~Router() {}

    void addRoute(const std::string& path, const std::string& root) {
        routes_[path] = root;
    }

    std::string getRootPath(const std::string& path) {
        std::map<std::string, std::string>::iterator it = routes_.find(path);
        if (it != routes_.end()) {
            return it->second;
        }
        return "UNKNOWN";  // 등록되지 않은 경로
    }

    void loadConfigRoute(const std::string& configFile) {
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
                currentRoot = "";  // 새로운 location이 나오면 root 초기화
    
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
    
    void printRoutes() {
        std::cout << "\n=== 전체 라우팅 테이블 ===\n";
        for (std::map<std::string, std::string>::iterator it = routes_.begin(); it != routes_.end(); ++it) {
            std::cout << "Path: " << it->first << " -> Root: " << it->second << std::endl;
        }
    }
};

#endif

int main() {
    Router router;

    // ✅ 설정 파일을 로드하여 라우팅 테이블 생성
    router.loadConfigRoute("../default2.conf");

    // ✅ 전체 라우팅 테이블 출력
    router.printRoutes();

    return 0;
}
