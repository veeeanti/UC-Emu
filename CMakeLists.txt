cmake_minimum_required(VERSION 3.10)
project(SteamAPI_Emulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Set source files for the DLL
set(SOURCES
    src/dllmain.cpp
    src/SteamAPI.cpp
    src/SteamClient.cpp
    src/steam_api.rc
)

# Create the DLL for both x86 and x64
add_library(steam_api SHARED ${SOURCES})

# Set properties for Windows
if(WIN32)
    set_target_properties(steam_api PROPERTIES PREFIX "")
    set_target_properties(steam_api PROPERTIES SUFFIX ".dll")
endif()

# Create the test executable
add_executable(test_steam test.cpp)

# Link the test executable with the DLL
target_link_libraries(test_steam steam_api)