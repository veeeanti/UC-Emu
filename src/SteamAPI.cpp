#include "../include/SteamAPI.h"

// Declare the functions that are implemented in SteamClient.cpp
extern "C" ESteamAPIInitResult SteamAPI_Init_Impl();
extern "C" void SteamAPI_Shutdown_Impl();
extern "C" ISteamClient* SteamClient_Impl();
extern "C" ISteamUser* SteamUser_Impl();
extern "C" ISteamFriends* SteamFriends_Impl();
extern "C" ISteamUtils* SteamUtils_Impl();
extern "C" ISteamMatchmaking* SteamMatchmaking_Impl();
extern "C" ISteamUserStats* SteamUserStats_Impl();
extern "C" ISteamApps* SteamApps_Impl();
extern "C" ISteamNetworking* SteamNetworking_Impl();
extern "C" ISteamRemoteStorage* SteamRemoteStorage_Impl();
extern "C" ISteamScreenshots* SteamScreenshots_Impl();
extern "C" ISteamHTTP* SteamHTTP_Impl();
extern "C" ISteamUnifiedMessages* SteamUnifiedMessages_Impl();
extern "C" ISteamController* SteamController_Impl();
extern "C" ISteamUGC* SteamUGC_Impl();
extern "C" ISteamAppList* SteamAppList_Impl();
extern "C" ISteamMusic* SteamMusic_Impl();
extern "C" ISteamMusicRemote* SteamMusicRemote_Impl();
extern "C" ISteamHTMLSurface* SteamHTMLSurface_Impl();
extern "C" ISteamInventory* SteamInventory_Impl();
extern "C" ISteamVideo* SteamVideo_Impl();
extern "C" ISteamParentalSettings* SteamParentalSettings_Impl();
extern "C" ISteamInput* SteamInput_Impl();
extern "C" ISteamRemotePlay* SteamRemotePlay_Impl();
extern "C" ISteamNetworkingMessages* SteamNetworkingMessages_Impl();
extern "C" ISteamNetworkingSockets* SteamNetworkingSockets_Impl();
extern "C" ISteamNetworkingUtils* SteamNetworkingUtils_Impl();

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
        // Return true to indicate Steam is running, even if it's not (hopefully)
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
    
    __declspec(dllexport) void* SteamUserStats()
    {
        return SteamUserStats_Impl();
    }
    
    __declspec(dllexport) void* SteamApps()
    {
        return SteamApps_Impl();
    }
    
    __declspec(dllexport) void* SteamNetworking()
    {
        return SteamNetworking_Impl();
    }
    
    __declspec(dllexport) void* SteamRemoteStorage()
    {
        return SteamRemoteStorage_Impl();
    }
    
    __declspec(dllexport) void* SteamScreenshots()
    {
        return SteamScreenshots_Impl();
    }
    
    __declspec(dllexport) void* SteamHTTP()
    {
        return SteamHTTP_Impl();
    }
    
    __declspec(dllexport) void* SteamUnifiedMessages()
    {
        return SteamUnifiedMessages_Impl();
    }
    
    __declspec(dllexport) void* SteamController()
    {
        return SteamController_Impl();
    }
    
    __declspec(dllexport) void* SteamUGC()
    {
        return SteamUGC_Impl();
    }
    
    __declspec(dllexport) void* SteamAppList()
    {
        return SteamAppList_Impl();
    }
    
    __declspec(dllexport) void* SteamMusic()
    {
        return SteamMusic_Impl();
    }
    
    __declspec(dllexport) void* SteamMusicRemote()
    {
        return SteamMusicRemote_Impl();
    }
    
    __declspec(dllexport) void* SteamHTMLSurface()
    {
        return SteamHTMLSurface_Impl();
    }
    
    __declspec(dllexport) void* SteamInventory()
    {
        return SteamInventory_Impl();
    }
    
    __declspec(dllexport) void* SteamVideo()
    {
        return SteamVideo_Impl();
    }
    
    __declspec(dllexport) void* SteamParentalSettings()
    {
        return SteamParentalSettings_Impl();
    }
    
    __declspec(dllexport) void* SteamInput()
    {
        return SteamInput_Impl();
    }
    
    __declspec(dllexport) void* SteamRemotePlay()
    {
        return SteamRemotePlay_Impl();
    }
    
    __declspec(dllexport) void* SteamNetworkingMessages()
    {
        return SteamNetworkingMessages_Impl();
    }
    
    __declspec(dllexport) void* SteamNetworkingSockets()
    {
        return SteamNetworkingSockets_Impl();
    }
    
    __declspec(dllexport) void* SteamNetworkingUtils()
    {
        return SteamNetworkingUtils_Impl();
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
        return "C:\\Program Files (x86)\\Steam"; // Default Steam install path
    }
    
    __declspec(dllexport) const char* SteamAPI_GetSteamUserBase()
    {
        return "C:\\Program Files (x86)\\Steam\\userdata"; // Default Steam userdata / user base path
    }
    
    __declspec(dllexport) void* SteamAPI_CreateInterface(const char* pName, int* pReturnCode)
    {
        return nullptr; // Dummy implementation
    }
    
    __declspec(dllexport) void SteamInternal_CreateInterface(const char *pchVersion)
    {
        // Dummy implementation?
    }
    
    // SteamGameServer functions
    __declspec(dllexport) void* SteamGameServer()
    {
        return nullptr; // Dummy implementation
    }
    
    __declspec(dllexport) void SteamGameServer_Shutdown()
    {
        // Dummy implementation
    }
    
    __declspec(dllexport) void SteamGameServer_RunCallbacks()
    {
        // Dummy implementation
    }
    
    __declspec(dllexport) bool SteamGameServer_BSecure()
    {
        return false; // Dummy implementation
    }
    
    __declspec(dllexport) uint64 SteamGameServer_GetSteamID()
    {
        return 0; // Dummy implementation
    }
    
    __declspec(dllexport) bool SteamGameServer_Init(uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char* pchVersionString)
    {
        return true; // Dummy implementation - always succeed
    }
}