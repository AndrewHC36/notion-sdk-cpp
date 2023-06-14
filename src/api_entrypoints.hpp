#ifndef __NPP_API_ENTRYPOINTS_H__
#define __NPP_API_ENTRYPOINTS_H__


#include <cpr/cpr.h>

namespace {


class Endpoint {
protected:
};


}  // private namespace


namespace notion {


class BlocksChildrenEndpoint final : private Endpoint {
    cpr::Response append();
    cpr::Response list();
};

class BlocksEndpoint final : private Endpoint {
    BlocksChildrenEndpoint children;

    cpr::Response retrieve();
    cpr::Response update();
    cpr::Response delete_();
};

class PagesPropertiesEndpoint final : private Endpoint {
    cpr::Response retrieve();
};

class PagesEndpoint final : private Endpoint {
    PagesPropertiesEndpoint properties;

    cpr::Response create();
    cpr::Response retrieve();
    cpr::Response update();
};

class DatabasesEndpoint final : private Endpoint {
    // cpr::Response list();  // deprecated
    cpr::Response query();
    cpr::Response retrieve();
    cpr::Response create();
    cpr::Response update();
};

class UsersEndpoint final : private Endpoint {
    cpr::Response list();
    cpr::Response retrieve();
    cpr::Response me();
};

class CommentsEndpoint final : private Endpoint {
    cpr::Response create();
    cpr::Response list();
};

class SearchEndpoint final : private Endpoint {
    cpr::Response operator()();
};


} // namespace notion


#endif
