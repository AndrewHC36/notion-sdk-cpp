#ifndef __NPP_CLIENT_H__
#define __NPP_CLIENT_H__

#include "api_entrypoints.hpp"
#include "async_api_entrypoints.hpp"

#include <string>

namespace notion {


struct ClientOptions {
    std::string auth;
    int timeout_ms;
    std::string base_url;
    int log_level;
    int logger;
    std::string version = "2022-06-28";
};

class Client {
private:
    struct Async {
        AsyncBlocksEndpoint blocks;
        AsyncDatabasesEndpoint databases;
        AsyncUsersEndpoint users;
        AsyncPagesEndpoint pages;
        AsyncCommentsEndpoint comments;
        AsyncSearchEndpoint search;
    };

    ClientOptions options;

public:
    BlocksEndpoint blocks;
    DatabasesEndpoint databases;
    UsersEndpoint users;
    PagesEndpoint pages;
    CommentsEndpoint comments;
    SearchEndpoint search;

    Async async;

    Client(ClientOptions options);
};


} // namespace notion

#endif
