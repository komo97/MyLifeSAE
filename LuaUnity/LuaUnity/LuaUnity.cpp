#include "LuaUnity.h"
#include "lua.hpp"
#include <string>

		using namespace std;

		extern "C" {

			static int setText(lua_State *L) {
				int id = lua_tonumber(L, 1);
				string text = lua_tostring(L, 2);
				Page p;
				History::getPtr()->pages.insert(std::pair<int, Page>(id, p));
				History::getPtr()->pages[id].texts.push_back(text);
			
				return 1;
			}

			static int setCloseAnswer(lua_State *L) {
				double id = lua_tonumber(L, 1);
				string text = lua_tostring(L, 2);
				double idJump = lua_tonumber(L, 3);
				lua_tocfunction(L, 4);

				return 1;
			}

			int GetPageNum()
			{
				return History::getPtr()->pages.size();
			}


			int GetPageNumTexts(int nPage)
			{
				return History::getPtr()->pages[nPage].texts.size();
			}

			const char* GetPage(int nPage, int idText)
			{
				if (idText >= 0 && idText < History::getPtr()->pages[nPage].texts.size())
				{
					return History::getPtr()->pages[nPage].texts[idText].c_str();
				}
				else
				{
					return "ERROR";
				}
			}

			int Load(char* level)
			{
				lua_State* L = luaL_newstate();
				luaL_openlibs(L);
				luaopen_base(L);
				luaopen_string(L);
				luaopen_math(L);

				lua_pushcfunction(L, setText);
				lua_setglobal(L, "setText");

				if (luaL_loadfile(L, level) || lua_pcall(L, 0, 0, 0))
				{

					return 2;
				}

				return 1;
			}
		}