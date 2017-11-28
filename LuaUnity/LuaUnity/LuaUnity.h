
#ifdef LUAUNITYFUNCDLL_EXPORT
#define LUAUNITYFUNCDLL_EXPORT __declspec(dllexport) 
#else
#define LUAUNITYFUNCDLL_EXPORT __declspec(dllimport) 
#endif
#include <iostream>
#include "History.h"

using namespace std;

extern "C" {
	LUAUNITYFUNCDLL_EXPORT int Load(char* level);

	LUAUNITYFUNCDLL_EXPORT const char* GetPage(int nPage, int idText);
	LUAUNITYFUNCDLL_EXPORT int GetPageNum();
	LUAUNITYFUNCDLL_EXPORT int GetPageNumTexts(int nPage);
}
