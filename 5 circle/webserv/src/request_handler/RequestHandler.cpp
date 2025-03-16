#include "RequestHandler.hpp"

RequestHandler::~RequestHandler() {}

RequestHandler::RequestHandler(ServerConfig &serverConfig, Request &request, Kqueue& kqueue) 
    : router_(serverConfig), cgiHandler_(kqueue), request_(request) {
        std::cout << "\n\n\n\n" << "RequestHandler initialized!\n\n\n\n" << std::endl;
    }

void RequestHandler::handleRequest(const Request& request, int clientFd) { // path가 없는 경우 에러처리는 convertPath에서 처리
    if (request.getExtension() == ".py") {
        PathInfo pathInfo = router_.convertPath(request.getPath(), true);
        cgiHandler_.processCgiRequest(request, clientFd, pathInfo);
    }
    // cgi가 아니면 그냥 else문 없이 그냥 바로 정적요청 처리
    PathInfo pathInfo = router_.convertPath(request.getPath(), false);
    // ex) staticResourceHandler_.serveStaticResource(request.getPath(), clientFd);
}
