#ifndef STEAM_API_H
#define STEAM_API_H

// Basic Steam API interface definitions
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned long long uint64;

// Steam API return values
enum ESteamAPIInitResult
{
    k_ESteamAPIInitResult_OK = 0,
    k_ESteamAPIInitResult_FailedGeneric = 1,
    k_ESteamAPIInitResult_NoSteamClient = 2,
    k_ESteamAPIInitResult_VersionMismatch = 3,
};

// Steam interface versions
#define STEAMCLIENT_INTERFACE_VERSION_017 "SteamClient017"
#define STEAMUSER_INTERFACE_VERSION_017 "SteamUser017"
#define STEAMFRIENDS_INTERFACE_VERSION_015 "SteamFriends015"
#define STEAMUTILS_INTERFACE_VERSION_007 "SteamUtils007"
#define STEAMUTILS_INTERFACE_VERSION_009 "SteamUtils009"
#define STEAMMATCHMAKING_INTERFACE_VERSION_009 "SteamMatchMaking009"

// Forward declarations
class ISteamClient;
class ISteamUser;
class ISteamFriends;
class ISteamUtils;
class ISteamMatchmaking;

// Steam API functions
extern "C" 
{
    __declspec(dllexport) ESteamAPIInitResult SteamAPI_Init();
    __declspec(dllexport) void SteamAPI_Shutdown();
    __declspec(dllexport) void SteamAPI_RunCallbacks();
    __declspec(dllexport) bool SteamAPI_IsSteamRunning();
    __declspec(dllexport) ISteamClient* SteamClient();
    __declspec(dllexport) ISteamUser* SteamUser();
    __declspec(dllexport) ISteamFriends* SteamFriends();
    __declspec(dllexport) ISteamUtils* SteamUtils();
    __declspec(dllexport) ISteamMatchmaking* SteamMatchmaking();
}

// Base interface class
class ISteamClient
{
public:
    virtual ~ISteamClient() {}
};

// SteamUser interface
class ISteamUser
{
public:
    virtual ~ISteamUser() {}
    
    // Returns the Steam user ID of the account
    virtual uint64 GetSteamID() = 0;
    
    // Returns true if the user is logged into Steam
    virtual bool BLoggedOn() = 0;
};

// SteamFriends interface
class ISteamFriends
{
public:
    virtual ~ISteamFriends() {}
    
    // Returns the local player's name
    virtual const char* GetPersonaName() = 0;
    
    // Sets the player name
    virtual void SetPersonaName(const char* pchPersonaName) = 0;
};

// SteamUtils interface
class ISteamUtils
{
public:
    virtual ~ISteamUtils() {}
    
    // Returns the number of seconds since the Unix epoch
    virtual uint32 GetSecondsSinceAppActive() = 0;
    
    // Returns the Steam universe this client is running in
    virtual uint32 GetConnectedUniverse() = 0;
};

// SteamMatchmaking interface
class ISteamMatchmaking
{
public:
    virtual ~ISteamMatchmaking() {}
    
    // Gets the number of active players
    virtual int GetFavoriteGameCount() = 0;
    
    // Adds a server to the list of favorites
    virtual bool AddFavoriteGame(uint32 nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) = 0;
};

#endif // STEAM_API_H