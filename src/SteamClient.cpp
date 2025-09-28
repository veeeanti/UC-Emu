#include "../include/SteamAPI.h"
#include <iostream>
#include <string>
#include <ctime>

// SteamClient implementation
class CSteamClient : public ISteamClient
{
public:
    CSteamClient() {}
    virtual ~CSteamClient() {}
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
    CSteamFriends() : m_personaName("Player") {}
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
    CSteamUtils() {}
    virtual ~CSteamUtils() {}
    
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
    int m_favoriteGameCount;
    
public:
    CSteamMatchmaking() : m_favoriteGameCount(0) {}
    virtual ~CSteamMatchmaking() {}
    
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

// Global variables for interface instances
static CSteamClient* g_pSteamClient = nullptr;
static CSteamUser* g_pSteamUser = nullptr;
static CSteamFriends* g_pSteamFriends = nullptr;
static CSteamUtils* g_pSteamUtils = nullptr;
static CSteamMatchmaking* g_pSteamMatchmaking = nullptr;

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
    
    return k_ESteamAPIInitResult_OK;
}

extern "C" void SteamAPI_Shutdown_Impl()
{
    std::cout << "SteamAPI_Shutdown called" << std::endl;
    
    // Clean up interface instances
    delete g_pSteamMatchmaking;
    delete g_pSteamUtils;
    delete g_pSteamFriends;
    delete g_pSteamUser;
    delete g_pSteamClient;
    
    g_pSteamClient = nullptr;
    g_pSteamUser = nullptr;
    g_pSteamFriends = nullptr;
    g_pSteamUtils = nullptr;
    g_pSteamMatchmaking = nullptr;
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