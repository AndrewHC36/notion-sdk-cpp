// #include "../include/notion.hpp"
#include <notion.hpp>
#include <cpr/cpr.h>

#include <iostream>
#include <fstream>

int test_prelude(int argc, char** const argv) {
    std::string AUTH;

    std::ifstream f;
    f.open("../SECRET");
    f >> AUTH;
    f.close();

    cpr::Response notion_auth = cpr::Get(
        cpr::Url{"https://api.notion.com/v1/pages/0000ab186c2b4eadbe2548c4f7ebe798"},
        cpr::Bearer{AUTH},
        cpr::Header{{"Notion-Version", "2022-06-28"}}
    );

    std::cout << notion_auth.status_code << std::endl;
    std::cout << notion_auth.header["content-type"] << std::endl;
    std::cout << notion_auth.text << std::endl;
    if(notion_auth.status_code != 200) return 1;

    return 0;
}
