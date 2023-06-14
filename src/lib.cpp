#include "api_entrypoints.hpp"
#include "async_api_entrypoints.hpp"
#include "client.hpp"


// MVP: able to use Notion through this library via very basic structure w/o custom types, json parsing, etc.

// use an external json library to parse into json types back, 
// but use custom/CPR types to encode data back into CPR-ready param
// what about json output into CPR types?

// api usage psuedocode
/*
#include "notion.hpp"

    // authenticating (or loading token)
    ??? TOKEN = notionSDK::OAuth();

    // using the library
    Client notion = new notionSDK::Client(TOKEN);  <-- library entrypoint

    notion.pages.retrieve() <-- somehow obtain block ID?

    notion.block.retrieve() / update() / ..
*/
