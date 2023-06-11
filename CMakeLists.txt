cmake_minimum_required(VERSION 3.21.0)
project(notion-sdk-cpp VERSION 0.0.1 LANGUAGES C CXX)
# lower standard to support as much application as possible,
# unless new features really are needed
set_property(GLOBAL PROPERTY CXX_STANDARD C++17)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

# === DEPENDENCIES ===
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

# === PROJECT ===
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
target_link_libraries(NotionSDK PRIVATE cpr::cpr)
# resolves any DLL linking issues
add_custom_command(TARGET NotionSDK POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:NotionSDK> $<TARGET_RUNTIME_DLLS:NotionSDK>
  COMMAND_EXPAND_LISTS
)

# === TESTING ===
include(CTest)
enable_testing() # ctest -C Debug

# create the testing file and list of tests
create_test_sourcelist (Tests
    test/testmain.cpp
    test/prelude.cpp
    test/requesting.cpp
  )

# linking ext dep and NotionSDK itself to each tests
add_executable (CommonTests ${Tests})
target_link_libraries(CommonTests PRIVATE cpr::cpr)
target_link_libraries(CommonTests PRIVATE NotionSDK)

# remove the test driver source file
set (TestFiles ${Tests})
remove (TestFiles test/testmain.cpp)

# Add all the ADD_TEST for each test
foreach (test ${TestFiles})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND CommonTests test/${TName})
endforeach ()

# === PACKAGING ===
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
