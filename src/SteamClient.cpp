#include "../include/SteamAPI.h"
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

// SteamClient implementation
class CSteamClient : public ISteamClient
{
public:
    // Using default constructor and destructor
};

// SteamUser implementation
class CSteamUser : public ISteamUser
{
private:
    uint64 m_steamID;
    bool m_bLoggedOn;
    
public:
    CSteamUser() : m_steamID(123456789), m_bLoggedOn(true) {}
    virtual ~CSteamUser() {}
    
    // Returns the Steam user ID of the account
    virtual uint64 GetSteamID() override
    {
        return m_steamID;
    }
    
    // Returns true if the user is logged into Steam
    virtual bool BLoggedOn() override
    {
        return m_bLoggedOn;
    }
};

// SteamFriends implementation
class CSteamFriends : public ISteamFriends
{
private:
    std::string m_personaName;
    
public:
    CSteamFriends() : m_personaName("union-crax") {}
    virtual ~CSteamFriends() {}
    
    // Returns the local player's name
    virtual const char* GetPersonaName() override
    {
        return m_personaName.c_str();
    }
    
    // Sets the player name
    virtual void SetPersonaName(const char* pchPersonaName) override
    {
        if (pchPersonaName)
        {
            m_personaName = pchPersonaName;
        }
    }
};

// SteamUtils implementation
class CSteamUtils : public ISteamUtils
{
public:
    // Using default constructor and destructor
    
    // Returns the number of seconds since the Unix epoch
    virtual uint32 GetSecondsSinceAppActive() override
    {
        return static_cast<uint32>(std::time(nullptr));
    }
    
    // Returns the Steam universe this client is running in
    virtual uint32 GetConnectedUniverse() override
    {
        return 1; // Assume public universe
    }
};

// SteamMatchmaking implementation
class CSteamMatchmaking : public ISteamMatchmaking
{
private:
    int m_favoriteGameCount = 0; // Initialize directly
    
public:
    // Using default destructor
    
    // Gets the number of active players
    virtual int GetFavoriteGameCount() override
    {
        return m_favoriteGameCount;
    }
    
    // Adds a server to the list of favorites
    virtual bool AddFavoriteGame(uint32 nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) override
    {
        m_favoriteGameCount++;
        return true;
    }
};

// Additional interface implementations
class CSteamUserStats : public ISteamUserStats
{
public:
    virtual ~CSteamUserStats() {}
};

class CSteamApps : public ISteamApps
{
public:
    virtual ~CSteamApps() {}
};

class CSteamNetworking : public ISteamNetworking
{
public:
    virtual ~CSteamNetworking() {}
};

class CSteamRemoteStorage : public ISteamRemoteStorage
{
public:
    virtual ~CSteamRemoteStorage() {}
};

class CSteamScreenshots : public ISteamScreenshots
{
public:
    virtual ~CSteamScreenshots() {}
};

class CSteamHTTP : public ISteamHTTP
{
public:
    virtual ~CSteamHTTP() {}
};

class CSteamUnifiedMessages : public ISteamUnifiedMessages
{
public:
    virtual ~CSteamUnifiedMessages() {}
};

class CSteamController : public ISteamController
{
public:
    virtual ~CSteamController() {}
};

class CSteamUGC : public ISteamUGC
{
public:
    virtual ~CSteamUGC() {}
};

class CSteamAppList : public ISteamAppList
{
public:
    virtual ~CSteamAppList() {}
};

class CSteamMusic : public ISteamMusic
{
public:
    virtual ~CSteamMusic() {}
};

class CSteamMusicRemote : public ISteamMusicRemote
{
public:
    virtual ~CSteamMusicRemote() {}
};

class CSteamHTMLSurface : public ISteamHTMLSurface
{
public:
    virtual ~CSteamHTMLSurface() {}
};

class CSteamInventory : public ISteamInventory
{
public:
    virtual ~CSteamInventory() {}
};

class CSteamVideo : public ISteamVideo
{
public:
    virtual ~CSteamVideo() {}
};

class CSteamParentalSettings : public ISteamParentalSettings
{
public:
    virtual ~CSteamParentalSettings() {}
};

class CSteamInput : public ISteamInput
{
public:
    virtual ~CSteamInput() {}
};

class CSteamRemotePlay : public ISteamRemotePlay
{
public:
    virtual ~CSteamRemotePlay() {}
};

class CSteamNetworkingMessages : public ISteamNetworkingMessages
{
public:
    virtual ~CSteamNetworkingMessages() {}
};

class CSteamNetworkingSockets : public ISteamNetworkingSockets
{
public:
    virtual ~CSteamNetworkingSockets() {}
};

class CSteamNetworkingUtils : public ISteamNetworkingUtils
{
public:
    virtual ~CSteamNetworkingUtils() {}
};

// Global variables for interface instances
static CSteamClient* g_pSteamClient = nullptr;
static CSteamUser* g_pSteamUser = nullptr;
static CSteamFriends* g_pSteamFriends = nullptr;
static CSteamUtils* g_pSteamUtils = nullptr;
static CSteamMatchmaking* g_pSteamMatchmaking = nullptr;
static CSteamUserStats* g_pSteamUserStats = nullptr;
static CSteamApps* g_pSteamApps = nullptr;
static CSteamNetworking* g_pSteamNetworking = nullptr;
static CSteamRemoteStorage* g_pSteamRemoteStorage = nullptr;
static CSteamScreenshots* g_pSteamScreenshots = nullptr;
static CSteamHTTP* g_pSteamHTTP = nullptr;
static CSteamUnifiedMessages* g_pSteamUnifiedMessages = nullptr;
static CSteamController* g_pSteamController = nullptr;
static CSteamUGC* g_pSteamUGC = nullptr;
static CSteamAppList* g_pSteamAppList = nullptr;
static CSteamMusic* g_pSteamMusic = nullptr;
static CSteamMusicRemote* g_pSteamMusicRemote = nullptr;
static CSteamHTMLSurface* g_pSteamHTMLSurface = nullptr;
static CSteamInventory* g_pSteamInventory = nullptr;
static CSteamVideo* g_pSteamVideo = nullptr;
static CSteamParentalSettings* g_pSteamParentalSettings = nullptr;
static CSteamInput* g_pSteamInput = nullptr;
static CSteamRemotePlay* g_pSteamRemotePlay = nullptr;
static CSteamNetworkingMessages* g_pSteamNetworkingMessages = nullptr;
static CSteamNetworkingSockets* g_pSteamNetworkingSockets = nullptr;
static CSteamNetworkingUtils* g_pSteamNetworkingUtils = nullptr;

// Implementation of the API functions
extern "C" ESteamAPIInitResult SteamAPI_Init_Impl()
{
    std::cout << "SteamAPI_Init called" << std::endl;
    
    // Create interface instances
    g_pSteamClient = new CSteamClient();
    g_pSteamUser = new CSteamUser();
    g_pSteamFriends = new CSteamFriends();
    g_pSteamUtils = new CSteamUtils();
    g_pSteamMatchmaking = new CSteamMatchmaking();
    g_pSteamUserStats = new CSteamUserStats();
    g_pSteamApps = new CSteamApps();
    g_pSteamNetworking = new CSteamNetworking();
    g_pSteamRemoteStorage = new CSteamRemoteStorage();
    g_pSteamScreenshots = new CSteamScreenshots();
    g_pSteamHTTP = new CSteamHTTP();
    g_pSteamUnifiedMessages = new CSteamUnifiedMessages();
    g_pSteamController = new CSteamController();
    g_pSteamUGC = new CSteamUGC();
    g_pSteamAppList = new CSteamAppList();
    g_pSteamMusic = new CSteamMusic();
    g_pSteamMusicRemote = new CSteamMusicRemote();
    g_pSteamHTMLSurface = new CSteamHTMLSurface();
    g_pSteamInventory = new CSteamInventory();
    g_pSteamVideo = new CSteamVideo();
    g_pSteamParentalSettings = new CSteamParentalSettings();
    g_pSteamInput = new CSteamInput();
    g_pSteamRemotePlay = new CSteamRemotePlay();
    g_pSteamNetworkingMessages = new CSteamNetworkingMessages();
    g_pSteamNetworkingSockets = new CSteamNetworkingSockets();
    g_pSteamNetworkingUtils = new CSteamNetworkingUtils();
    
    return k_ESteamAPIInitResult_OK;
}

extern "C" void SteamAPI_Shutdown_Impl()
{
    std::cout << "SteamAPI_Shutdown called" << std::endl;
    
    // Clean up interface instances
    delete g_pSteamNetworkingUtils;
    delete g_pSteamNetworkingSockets;
    delete g_pSteamNetworkingMessages;
    delete g_pSteamRemotePlay;
    delete g_pSteamInput;
    delete g_pSteamParentalSettings;
    delete g_pSteamVideo;
    delete g_pSteamInventory;
    delete g_pSteamHTMLSurface;
    delete g_pSteamMusicRemote;
    delete g_pSteamMusic;
    delete g_pSteamAppList;
    delete g_pSteamUGC;
    delete g_pSteamController;
    delete g_pSteamUnifiedMessages;
    delete g_pSteamHTTP;
    delete g_pSteamScreenshots;
    delete g_pSteamRemoteStorage;
    delete g_pSteamNetworking;
    delete g_pSteamApps;
    delete g_pSteamUserStats;
    delete g_pSteamMatchmaking;
    delete g_pSteamUtils;
    delete g_pSteamFriends;
    delete g_pSteamUser;
    delete g_pSteamClient;
    
    // Reset pointers to nullptr
    g_pSteamClient = nullptr;
    g_pSteamUser = nullptr;
    g_pSteamFriends = nullptr;
    g_pSteamUtils = nullptr;
    g_pSteamMatchmaking = nullptr;
    g_pSteamUserStats = nullptr;
    g_pSteamApps = nullptr;
    g_pSteamNetworking = nullptr;
    g_pSteamRemoteStorage = nullptr;
    g_pSteamScreenshots = nullptr;
    g_pSteamHTTP = nullptr;
    g_pSteamUnifiedMessages = nullptr;
    g_pSteamController = nullptr;
    g_pSteamUGC = nullptr;
    g_pSteamAppList = nullptr;
    g_pSteamMusic = nullptr;
    g_pSteamMusicRemote = nullptr;
    g_pSteamHTMLSurface = nullptr;
    g_pSteamInventory = nullptr;
    g_pSteamVideo = nullptr;
    g_pSteamParentalSettings = nullptr;
    g_pSteamInput = nullptr;
    g_pSteamRemotePlay = nullptr;
    g_pSteamNetworkingMessages = nullptr;
    g_pSteamNetworkingSockets = nullptr;
    g_pSteamNetworkingUtils = nullptr;
}

extern "C" ISteamClient* SteamClient_Impl()
{
    return g_pSteamClient;
}

extern "C" ISteamUser* SteamUser_Impl()
{
    return g_pSteamUser;
}

extern "C" ISteamFriends* SteamFriends_Impl()
{
    return g_pSteamFriends;
}

extern "C" ISteamUtils* SteamUtils_Impl()
{
    return g_pSteamUtils;
}

extern "C" ISteamMatchmaking* SteamMatchmaking_Impl()
{
    return g_pSteamMatchmaking;
}

extern "C" ISteamUserStats* SteamUserStats_Impl()
{
    return g_pSteamUserStats;
}

extern "C" ISteamApps* SteamApps_Impl()
{
    return g_pSteamApps;
}

extern "C" ISteamNetworking* SteamNetworking_Impl()
{
    return g_pSteamNetworking;
}

extern "C" ISteamRemoteStorage* SteamRemoteStorage_Impl()
{
    return g_pSteamRemoteStorage;
}

extern "C" ISteamScreenshots* SteamScreenshots_Impl()
{
    return g_pSteamScreenshots;
}

extern "C" ISteamHTTP* SteamHTTP_Impl()
{
    return g_pSteamHTTP;
}

extern "C" ISteamUnifiedMessages* SteamUnifiedMessages_Impl()
{
    return g_pSteamUnifiedMessages;
}

extern "C" ISteamController* SteamController_Impl()
{
    return g_pSteamController;
}

extern "C" ISteamUGC* SteamUGC_Impl()
{
    return g_pSteamUGC;
}

extern "C" ISteamAppList* SteamAppList_Impl()
{
    return g_pSteamAppList;
}

extern "C" ISteamMusic* SteamMusic_Impl()
{
    return g_pSteamMusic;
}

extern "C" ISteamMusicRemote* SteamMusicRemote_Impl()
{
    return g_pSteamMusicRemote;
}

extern "C" ISteamHTMLSurface* SteamHTMLSurface_Impl()
{
    return g_pSteamHTMLSurface;
}

extern "C" ISteamInventory* SteamInventory_Impl()
{
    return g_pSteamInventory;
}

extern "C" ISteamVideo* SteamVideo_Impl()
{
    return g_pSteamVideo;
}

extern "C" ISteamParentalSettings* SteamParentalSettings_Impl()
{
    return g_pSteamParentalSettings;
}

extern "C" ISteamInput* SteamInput_Impl()
{
    return g_pSteamInput;
}

extern "C" ISteamRemotePlay* SteamRemotePlay_Impl()
{
    return g_pSteamRemotePlay;
}

extern "C" ISteamNetworkingMessages* SteamNetworkingMessages_Impl()
{
    return g_pSteamNetworkingMessages;
}

extern "C" ISteamNetworkingSockets* SteamNetworkingSockets_Impl()
{
    return g_pSteamNetworkingSockets;
}

extern "C" ISteamNetworkingUtils* SteamNetworkingUtils_Impl()
{
    return g_pSteamNetworkingUtils;
}

extern "C" __declspec(dllexport) void* __cdecl CreateInterface(const char* pName, int* pReturnCode)
{
    // Directly return the appropriate interface instance based on the name
    if (strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_012) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_013) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_014) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_015) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_016) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_017) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_018) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_019) == 0 ||
        strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_020) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamClient;
    }
    
    if (strcmp(pName, STEAMUSER_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_012) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_013) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_014) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_015) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_016) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_017) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_018) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_019) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_020) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_021) == 0 ||
        strcmp(pName, STEAMUSER_INTERFACE_VERSION_022) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamUser;
    }
    
    if (strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_012) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_013) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_014) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_015) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_016) == 0 ||
        strcmp(pName, STEAMFRIENDS_INTERFACE_VERSION_017) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamFriends;
    }
    
    if (strcmp(pName, STEAMUTILS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMUTILS_INTERFACE_VERSION_009) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamUtils;
    }
    
    if (strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMMATCHMAKING_INTERFACE_VERSION_009) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamMatchmaking;
    }
    
    if (strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMUSERSTATS_INTERFACE_VERSION_012) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamUserStats;
    }
    
    if (strcmp(pName, STEAMAPPS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMAPPS_INTERFACE_VERSION_008) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamApps;
    }
    
    if (strcmp(pName, STEAMNETWORKING_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMNETWORKING_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMNETWORKING_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMNETWORKING_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMNETWORKING_INTERFACE_VERSION_005) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamNetworking;
    }
    
    if (strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_012) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_013) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_014) == 0 ||
        strcmp(pName, STEAMREMOTESTORAGE_INTERFACE_VERSION_015) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamRemoteStorage;
    }
    
    if (strcmp(pName, STEAMSCREENSHOTS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMSCREENSHOTS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMSCREENSHOTS_INTERFACE_VERSION_003) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamScreenshots;
    }
    
    if (strcmp(pName, STEAMHTTP_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMHTTP_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMHTTP_INTERFACE_VERSION_003) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamHTTP;
    }
    
    if (strcmp(pName, STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamUnifiedMessages;
    }
    
    if (strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMCONTROLLER_INTERFACE_VERSION_007) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamController;
    }
    
    if (strcmp(pName, STEAMUGC_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_007) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_012) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_013) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_014) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_015) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_016) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_017) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_018) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_019) == 0 ||
        strcmp(pName, STEAMUGC_INTERFACE_VERSION_020) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamUGC;
    }
    
    if (strcmp(pName, STEAMAPPLIST_INTERFACE_VERSION_001) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamAppList;
    }
    
    if (strcmp(pName, STEAMMUSIC_INTERFACE_VERSION_001) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamMusic;
    }
    
    if (strcmp(pName, STEAMMUSICREMOTE_INTERFACE_VERSION_001) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamMusicRemote;
    }
    
    if (strcmp(pName, STEAMHTMLSURFACE_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMHTMLSURFACE_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMHTMLSURFACE_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMHTMLSURFACE_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMHTMLSURFACE_INTERFACE_VERSION_005) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamHTMLSurface;
    }
    
    if (strcmp(pName, STEAMPARENTALSETTINGS_INTERFACE_VERSION_001) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamParentalSettings;
    }
    
    if (strcmp(pName, STEAMINPUT_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMINPUT_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMINPUT_INTERFACE_VERSION_005) == 0 ||
        strcmp(pName, STEAMINPUT_INTERFACE_VERSION_006) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamInput;
    }
    
    if (strcmp(pName, STEAMREMOTEPLAY_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMREMOTEPLAY_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMREMOTEPLAY_INTERFACE_VERSION_003) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamRemotePlay;
    }
    
    if (strcmp(pName, STEAMNETWORKINGMESSAGES_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMNETWORKINGMESSAGES_INTERFACE_VERSION_002) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamNetworkingMessages;
    }
    
    if (strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_004) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_006) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_008) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_009) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_010) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_011) == 0 ||
        strcmp(pName, STEAMNETWORKINGSOCKETS_INTERFACE_VERSION_012) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamNetworkingSockets;
    }
    
    if (strcmp(pName, STEAMNETWORKINGUTILS_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMNETWORKINGUTILS_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMNETWORKINGUTILS_INTERFACE_VERSION_003) == 0 ||
        strcmp(pName, STEAMNETWORKINGUTILS_INTERFACE_VERSION_004) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamNetworkingUtils;
    }
    
    if (strcmp(pName, STEAMINVENTORY_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMINVENTORY_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMINVENTORY_INTERFACE_VERSION_003) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamInventory;
    }
    
    if (strcmp(pName, STEAMVIDEO_INTERFACE_VERSION_001) == 0 ||
        strcmp(pName, STEAMVIDEO_INTERFACE_VERSION_002) == 0 ||
        strcmp(pName, STEAMVIDEO_INTERFACE_VERSION_007) == 0) {
        if (pReturnCode) *pReturnCode = 0; // IFACE_OK
        return g_pSteamVideo;
    }
    
    // Unknown interface
    if (pReturnCode) *pReturnCode = 1; // IFACE_FAILED
    return nullptr;
}
