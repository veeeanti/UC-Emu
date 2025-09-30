#include "../include/SteamAPI.h"

// Declare the functions that are implemented in SteamClient.cpp
extern "C" ESteamAPIInitResult SteamAPI_Init_Impl();
extern "C" void SteamAPI_Shutdown_Impl();
extern "C" ISteamClient* SteamClient_Impl();
extern "C" ISteamUser* SteamUser_Impl();
extern "C" ISteamFriends* SteamFriends_Impl();
extern "C" ISteamUtils* SteamUtils_Impl();
extern "C" ISteamMatchmaking* SteamMatchmaking_Impl();

// Steam API implementation
extern "C" 
{
    __declspec(dllexport) ESteamAPIInitResult SteamAPI_Init()
    {
        return SteamAPI_Init_Impl();
    }
    
    __declspec(dllexport) void SteamAPI_Shutdown()
    {
        SteamAPI_Shutdown_Impl();
    }
    
    __declspec(dllexport) void SteamAPI_RunCallbacks()
    {
        // Process Steam callbacks
    }
    
    __declspec(dllexport) bool SteamAPI_IsSteamRunning()
    {
        // Return true to indicate Steam is running
        return true;
    }
    
    __declspec(dllexport) void* SteamClient()
    {
        return SteamClient_Impl();
    }
    
    __declspec(dllexport) void* SteamUser()
    {
        return SteamUser_Impl();
    }
    
    __declspec(dllexport) void* SteamFriends()
    {
        return SteamFriends_Impl();
    }
    
    __declspec(dllexport) void* SteamUtils()
    {
        return SteamUtils_Impl();
    }
    
    __declspec(dllexport) void* SteamMatchmaking()
    {
        return SteamMatchmaking_Impl();
    }

    __declspec(dllexport) uint32 SteamAPI_GetHSteamUser()
    {
        return 0; // Dummy HSteamUser value
    }
    
    __declspec(dllexport) uint32 SteamAPI_GetHSteamUserA()
    {
        return 0; // Dummy HSteamUserA value
    }
    
    __declspec(dllexport) uint32 SteamAPI_GetHSteamPipe()
    {
        return 0; // Dummy HSteamPipe value
    }
    
    __declspec(dllexport) uint32 SteamAPI_GetHSteamPipeA()
    {
        return 0; // Dummy HSteamPipeA value
    }
    
    __declspec(dllexport) const char* SteamAPI_GetSteamInstallPath()
    {
        return "C:\\Program Files (x86)\\Steam"; // Dummy Steam install path
    }
    
    __declspec(dllexport) const char* SteamAPI_GetSteamInstallPathA()
    {
        return "C:\\Program Files (x86)\\Steam"; // Dummy Steam install path
    }
    
    __declspec(dllexport) const char* SteamAPI_GetSteamUserBase()
    {
        return "C:\\Program Files (x86)\\Steam\\userdata"; // Dummy Steam user base path
    }
    
    __declspec(dllexport) void* SteamAPI_CreateInterface(const char* pName, int* pReturnCode)
    {
        return nullptr; // Dummy implementation
    }
    
    __declspec(dllexport) void SteamInternal_CreateInterface(const char *pchVersion)
    {
        // Dummy implementation
    }
}