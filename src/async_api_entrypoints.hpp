#ifndef __NPP_ASYNC_API_ENTRYPOINTS_H__
#define __NPP_ASYNC_API_ENTRYPOINTS_H__

#include <cpr/cpr.h>

namespace {


class AsyncEndpoint {
protected:
};


}  // private namespace


namespace notion {


class AsyncBlocksChildrenEndpoint final : private AsyncEndpoint {
    cpr::AsyncResponse append();
    cpr::AsyncResponse list();
};

class AsyncBlocksEndpoint final : private AsyncEndpoint {
    AsyncBlocksChildrenEndpoint children;
    
    cpr::AsyncResponse retrieve();
    cpr::AsyncResponse update();
    cpr::AsyncResponse delete_();
};

class AsyncPagesPropertiesEndpoint final : private AsyncEndpoint {
    cpr::AsyncResponse retrieve();
};

class AsyncPagesEndpoint final : private AsyncEndpoint {
    AsyncPagesPropertiesEndpoint properties;

    cpr::AsyncResponse create();
    cpr::AsyncResponse retrieve();
    cpr::AsyncResponse update();
};

class AsyncDatabasesEndpoint final : private AsyncEndpoint {
    // cpr::Response list();  // deprecated
    cpr::AsyncResponse query();
    cpr::AsyncResponse retrieve();
    cpr::AsyncResponse create();
    cpr::AsyncResponse update();
};

class AsyncUsersEndpoint final : private AsyncEndpoint {
    cpr::AsyncResponse list();
    cpr::AsyncResponse retrieve();
    cpr::AsyncResponse me();
};

class AsyncCommentsEndpoint final : private AsyncEndpoint {
    cpr::AsyncResponse create();
    cpr::AsyncResponse list();
};

class AsyncSearchEndpoint final : private AsyncEndpoint {
    cpr::AsyncResponse operator()();
};


}  // namespace notion

#endif
