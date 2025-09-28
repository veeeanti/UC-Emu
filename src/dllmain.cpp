#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize the DLL when it's loaded into a process
        break;
    case DLL_THREAD_ATTACH:
        // Initialize the DLL when a new thread is created
        break;
    case DLL_THREAD_DETACH:
        // Clean up when a thread exits
        break;
    case DLL_PROCESS_DETACH:
        // Clean up when the DLL is unloaded from a process
        break;
    }
    return TRUE;
}