/*
Rudimentary tests whether all CPR method used in NotionSDK works.
- Checks the method is working without error for this project
*/

#include <cpr/cpr.h>

#include <iostream>

int test_requesting(int argc, char** const argv) {
    std::cout << "Test requesting.cpp" << std::endl;

    // GET
    cpr::Response resp_get = cpr::Get(
        cpr::Url{"http://www.httpbin.org/get"},
        cpr::Parameters{{"param-key", "param-value"}, {"hello", "world"}}
    );

    std::cout << resp_get.url << std::endl;
    std::cout << resp_get.status_code << std::endl;
    std::cout << resp_get.header["content-type"] << std::endl;
    std::cout << resp_get.text << std::endl;

    // POST
    cpr::Response resp_post = cpr::Post(
        cpr::Url{"http://www.httpbin.org/post"},
        cpr::Payload{{"post-key", "post-value"}}
    );

    std::cout << resp_post.status_code << std::endl;

    // PATCH
    cpr::Response resp_patch = cpr::Patch(
        cpr::Url{"http://www.httpbin.org/patch"},
        cpr::Payload{{"patch-key", "patch-value"}}
    );

    std::cout << resp_post.status_code << std::endl;

    // DELETE
    cpr::Response resp_delete = cpr::Delete(
        cpr::Url{"http://www.httpbin.org/delete"}
    );

    std::cout << resp_delete.status_code << std::endl;

    // AUTHENTICATION: OAUTH V2.0 BEARER
    cpr::Response resp_auth_bearer = cpr::Get(
        cpr::Url{"https://httpbin.org/bearer"},
        cpr::Bearer{"TOKEN"}
    );

    std::cout << resp_auth_bearer.status_code << std::endl;

    return 0;
}
