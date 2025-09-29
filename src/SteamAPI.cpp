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
    
    __declspec(dllexport) ISteamClient* SteamClient()
    {
        return SteamClient_Impl();
    }
    
    __declspec(dllexport) ISteamUser* SteamUser()
    {
        return SteamUser_Impl();
    }
    
    __declspec(dllexport) ISteamFriends* SteamFriends()
    {
        return SteamFriends_Impl();
    }
    
    __declspec(dllexport) ISteamUtils* SteamUtils()
    {
        return SteamUtils_Impl();
    }
    
    __declspec(dllexport) ISteamMatchmaking* SteamMatchmaking()
    {
        return SteamMatchmaking_Impl();
    }

    __declspec(dllexport) uint32 SteamAPI_GetHSteamUser()
    {
        // Return a dummy HSteamUser value
        return 0;
    }

    __declspec(dllexport) uint32 SteamAPI_GetHSteamUserA()
    {
        // Return a dummy HSteamUserA value
        return 0;
    }

    __declspec(dllexport) uint32 SteamAPI_GetHSteamPipe()
    {
        // Return a dummy HSteamPipe value
        return 0;
    }

    __declspec(dllexport) uint32 SteamAPI_GetHSteamPipeA()
    {
        // Return a dummy HSteamPipeA value
        return 0;
    }

    __declspec(dllexport) const char* SteamAPI_GetSteamInstallPath()
    {
        // Return a dummy Steam install path
        return "C:\\Program Files (x86)\\Steam";
    }

    __declspec(dllexport) const char* SteamAPI_GetSteamInstallPathA()
    {
        // Return a dummy Steam install path
        return "C:\\Program Files (x86)\\Steam";
    }

    __declspec(dllexport) const char* SteamAPI_GetSteamUserBase()
    {
        // Return a dummy Steam user base path
        return "C:\\Program Files (x86)\\Steam\\userdata";
    }

    __declspec(dllexport) uint32 SteamAPI_CreateInterface()
    {
        // Dummy implementation
        return 0;
    }

    __declspec(dllexport) uint32 SteamAPI_CreateInterfaceA()
    {
        // Dummy implementation
        return 0;
    }

    __declspec(dllexport) void SteamInternal_CreateInterface(const char *pchVersion)
    {
        // Dummy implementation
    }
}