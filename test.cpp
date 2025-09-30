/*         
This doesn't work anymore. No clue as to why, it doesn't even work with the original steam_api.dll. Annoying ahh code.
~veeanti          
*/

#include <iostream>
#include <windows.h>

// Function pointer types
typedef int (*SteamAPI_InitFunc)();
typedef void (*SteamAPI_ShutdownFunc)();
typedef void (*SteamAPI_RunCallbacksFunc)();
typedef bool (*SteamAPI_IsSteamRunningFunc)();
typedef void* (*SteamClientFunc)();
typedef void* (*SteamUserFunc)();
typedef void* (*SteamFriendsFunc)();
typedef void* (*SteamUtilsFunc)();
typedef void* (*SteamMatchmakingFunc)();
typedef void* (*SteamAPI_CreateInterfaceFunc)(const char*, int*);

int main()
{
    // Load the DLL
    HMODULE hModule = LoadLibraryA("steam_api.dll");
    if (!hModule)
    {
        std::cerr << "Failed to load steam_api.dll" << std::endl;
        return 1;
    }
    
    // Get function pointers
    SteamAPI_InitFunc SteamAPI_Init = (SteamAPI_InitFunc)GetProcAddress(hModule, "SteamAPI_Init");
    SteamAPI_ShutdownFunc SteamAPI_Shutdown = (SteamAPI_ShutdownFunc)GetProcAddress(hModule, "SteamAPI_Shutdown");
    SteamAPI_RunCallbacksFunc SteamAPI_RunCallbacks = (SteamAPI_RunCallbacksFunc)GetProcAddress(hModule, "SteamAPI_RunCallbacks");
    SteamAPI_IsSteamRunningFunc SteamAPI_IsSteamRunning = (SteamAPI_IsSteamRunningFunc)GetProcAddress(hModule, "SteamAPI_IsSteamRunning");
    SteamClientFunc SteamClient = (SteamClientFunc)GetProcAddress(hModule, "SteamClient");
    SteamUserFunc SteamUser = (SteamUserFunc)GetProcAddress(hModule, "SteamUser");
    SteamFriendsFunc SteamFriends = (SteamFriendsFunc)GetProcAddress(hModule, "SteamFriends");
    SteamUtilsFunc SteamUtils = (SteamUtilsFunc)GetProcAddress(hModule, "SteamUtils");
    SteamMatchmakingFunc SteamMatchmaking = (SteamMatchmakingFunc)GetProcAddress(hModule, "SteamMatchmaking");
    SteamAPI_CreateInterfaceFunc SteamAPI_CreateInterface = (SteamAPI_CreateInterfaceFunc)GetProcAddress(hModule, "SteamAPI_CreateInterface");
    
    // Check if all functions were found
    if (!SteamAPI_Init || !SteamAPI_Shutdown || !SteamAPI_RunCallbacks ||
        !SteamAPI_IsSteamRunning || !SteamClient || !SteamUser ||
        !SteamFriends || !SteamUtils || !SteamMatchmaking || !SteamAPI_CreateInterface)
    {
        std::cerr << "Failed to get one or more function addresses" << std::endl;
        FreeLibrary(hModule);
        return 1;
    }
    
    // Test the functions
    std::cout << "Testing SteamAPI_Init..." << std::endl;
    int result = SteamAPI_Init();
    std::cout << "SteamAPI_Init returned: " << result << std::endl;
    
    std::cout << "Testing SteamAPI_IsSteamRunning..." << std::endl;
    bool isRunning = SteamAPI_IsSteamRunning();
    std::cout << "SteamAPI_IsSteamRunning returned: " << (isRunning ? "true" : "false") << std::endl;
    
    std::cout << "Testing SteamClient..." << std::endl;
    void* client = SteamClient();
    std::cout << "SteamClient returned: " << client << std::endl;
    
    std::cout << "Testing SteamUser..." << std::endl;
    void* user = SteamUser();
    std::cout << "SteamUser returned: " << user << std::endl;
    
    std::cout << "Testing SteamFriends..." << std::endl;
    void* friends = SteamFriends();
    std::cout << "SteamFriends returned: " << friends << std::endl;
    
    std::cout << "Testing SteamUtils..." << std::endl;
    void* utils = SteamUtils();
    std::cout << "SteamUtils returned: " << utils << std::endl;
    
    std::cout << "Testing SteamMatchmaking..." << std::endl;
    void* matchmaking = SteamMatchmaking();
    std::cout << "SteamMatchmaking returned: " << matchmaking << std::endl;
    
    std::cout << "Testing SteamAPI_RunCallbacks..." << std::endl;
    SteamAPI_RunCallbacks();
    std::cout << "SteamAPI_RunCallbacks completed" << std::endl;
    
    std::cout << "Testing SteamAPI_Shutdown..." << std::endl;
    SteamAPI_Shutdown();
    std::cout << "SteamAPI_Shutdown completed" << std::endl;
    
    // Clean up
    FreeLibrary(hModule);
    
    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}