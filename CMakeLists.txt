cmake_minimum_required(VERSION 3.0.0)
project(notion-sdk-cpp VERSION 0.0.1 LANGUAGES C CXX)
# lower standard to support as much application as possible,
# unless new features really are needed
set_property(GLOBAL PROPERTY CXX_STANDARD C++11)

# configures destination build DLLs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")

# configures to output library as DLL, not LIB
option(BUILD_SHARED_LIBS ON)

include_directories(include/)

add_library(NotionSDK SHARED
    src/lib.cpp
    src/api_entrypoints.cpp
)

include(CTest)
    if(BUILD_TESTING)  # ctest -C Debug
    enable_testing()

    # white-box testing
    add_executable(Tutorial test/tutorial.cpp)
    target_link_libraries(Tutorial PUBLIC NotionSDK)
    add_test(NAME Tutorial COMMAND Tutorial)

    # black-box testing

endif()

# ??? (no idea)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
