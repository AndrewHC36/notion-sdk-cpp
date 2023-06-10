#include "api_entrypoints.hpp"

// note: use __declspec(dllexport) if you want a specific object/type/function/etc. to be exposed
// for others using the final DLL file

// external libraries: CPR (Curl for People)

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
