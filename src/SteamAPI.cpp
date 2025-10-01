#include "../include/SteamAPI.h"

// Define PFNPreMinidumpCallback as a function pointer type if not already defined
typedef void (*PFNPreMinidumpCallback)(void*);

// Forward declaration for IGameEventListener to resolve identifier error
class IGameEventListener;

// Define SteamAPICall_t as a 64-bit unsigned integer if not already defined
typedef uint64 SteamAPICall_t;

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
        
    }
    
    __declspec(dllexport) void SteamGameServer_RunCallbacks()
    {
        
    }
    
    __declspec(dllexport) bool SteamGameServer_BSecure()
    {
        return false; // ah yes very bsecure, love it
    }
    
    __declspec(dllexport) uint64 SteamGameServer_GetSteamID()
    {
        return 0; // thats totally a valid steamid
    }
    
    __declspec(dllexport) bool SteamGameServer_Init(uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char* pchVersionString)
    {
        return true; // you have no choice - you must init
    }

    __declspec(dllexport) uint32 SteamInternal_ContextInit()
    {
        // So, one of the games i test with this has this import 
        //in one of the dlls it depends on to render the game's
        // graphics, it's Half-Life and the dll is hw.dll. It
        // relies on the steam_api.dll for whatever reason and is
        // really annoying too. -veeanti
        return 0;
    }

    __declspec(dllexport) void* SteamInternal_FindOrCreateUserInterface(uint32 hSteamUser, uint32 hSteamPipe, const char* pchVersion)
    {
        // i guess it couldnt find it, but it did find a nullpitter!
        return nullptr;
    }

    __declspec(dllexport) void* SteamInternal_FindOrCreateGameServerInterface(uint32 hSteamUser, uint32 hSteamPipe, const char* pchVersion)
    {
        
        return nullptr;
    }

    __declspec(dllexport) void* SteamInternal_GameServer_Init()
    {
        
        return nullptr;
    }

    __declspec(dllexport) bool SteamAPI_WriteMiniDump(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID)
    {
        
        return true;
    }

    __declspec(dllexport) bool SteamAPI_SetMiniDumpComment(const char *pchMsg)
    {
        
        return true;
    }

    __declspec(dllexport) void SteamAPI_UseBreakpadCrashHandler(
        const char* pchVersion,
        const char* pchDate,
        const char* pchTime,
        bool bFullMemoryDumps,
        void* pvContext,
        PFNPreMinidumpCallback m_pfnPreminidumpCallback
    )
    {
        // pingas
    }

    __declspec(dllexport) bool SteamAPI_SetBreakpadAppID( uint32 unAppID )
    {
        // quick question: what the fuck is a breakpadappid?
        return true;
    }

    __declspec(dllexport) bool SteamAPI_RegisterCallResult( SteamAPICall_t hAPICall, IGameEventListener* pListener )
    {
        // always succeed
        return true;
    }

    __declspec(dllexport) void SteamAPI_UnregisterCallResult( SteamAPICall_t hAPICall, IGameEventListener* pListener )
    {
        // always succeed...?
    }
}