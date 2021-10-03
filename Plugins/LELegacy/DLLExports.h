#pragma once
#include <string>
#include "../../Source/Libraries/PluginSDK/GMFSDK.h"
#include "../../Source/Libraries/PluginSDK/TextureInfo.h"
#include "../../Source/Libraries/PluginSDK/MemReader.h"
#include "../../Source/Libraries//nlohmann_json/single_include/nlohmann/json.hpp"
#include "../../Source/Libraries/PluginSDK/MemWriter.h"
#include "../../Source/Libraries/PluginSDK/Utilities.h"

#ifdef _WIN32
	#define DLLExport __declspec( dllexport )
#else
	#define DLLExport
#endif

using namespace GMFSDK;

class Context
{
public:
	std::string materialinfo;
	MemWriter writer;
	std::vector<void*> allocedmem;
};

extern "C"
{
	DLLExport Context* CreateContext();
	DLLExport BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved);
	DLLExport void* LoadTexture(Context*, void* data, uint64_t size, wchar_t* cpath, uint64_t& returnsize);
	DLLExport int GetPluginInfo(unsigned char* cs, int maxsize);
	DLLExport void FreeContext(Context*);
	DLLExport void* LoadMaterial(Context* context, void* data, uint64_t size, wchar_t* cpath, uint64_t& returnsize);
}