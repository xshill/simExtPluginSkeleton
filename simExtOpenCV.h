#pragma once

#ifdef _WIN32
    #define SIM_DLLEXPORT extern "C" __declspec(dllexport)
#else
    #define SIM_DLLEXPORT extern "C"
#endif

#define DEVELOPER_DATA_HEADER 92820

// The 3 required entry points of the CoppelisSim plugin:
SIM_DLLEXPORT unsigned char simStart(void* reservedPointer,int reservedInt);
SIM_DLLEXPORT void simEnd();
SIM_DLLEXPORT void* simMessage(int message,int* auxiliaryData,void* customData,int* replyData);
