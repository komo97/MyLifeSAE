#include "calc.flex.h"
#include "calc.tab.h"
#include "FlexBisonUnityDll.h"
#include <stdlib.h>
#include <future>

std::queue<BisonString> entryQueue, exitQueue;
std::thread bisonThread;
std::mutex mutex;
YY_BUFFER_STATE currBuffer = NULL;
std::string str;
yyscan_t scan;
bool programExecuting;


_declspec(dllexport) void __cdecl BisonOut(std::string out)
{
	str = out;
}

_declspec(dllexport) void __cdecl PushBisonString(char* str, size_t len)
{
	std::cout << str << std::endl;
	std::string testStr = str;
	testStr += '\n';
	testStr += '\0';
	testStr += '\0';
	char* finstr = new char[len + 3];
	strcpy_s(finstr, len + 3, testStr.c_str());
	mutex.lock();
	entryQueue.push(BisonString{ finstr, len + 3 });
	mutex.unlock();
}

_declspec(dllexport) BisonString __cdecl _GetBisonString()
{
	BisonString string = { "",0 };
	while (exitQueue.empty());
	mutex.lock();
	if (!exitQueue.empty())
	{
		string = exitQueue.front();
		exitQueue.pop();
	}
	mutex.unlock();
	return string;
}

_declspec(dllexport) BisonString __cdecl GetBisonString()
{
	auto future = std::async(_GetBisonString);
	BisonString ret = future.get();
	return ret;
}
_declspec(dllexport) void __cdecl BisonExecution()
{
	using namespace std::chrono_literals;
	while (programExecuting)
	{
		if (!entryQueue.empty())
		{
			if (currBuffer)
				yy_delete_buffer(currBuffer, scan);
			mutex.lock();
			currBuffer = yy_scan_string(entryQueue.front().str, scan);
			yy_switch_to_buffer(currBuffer, scan);
			entryQueue.pop();
			int a;
			if (!yyparse(scan))
			{
				BisonString string;
				string.len = str.length() + 1;
				string.str = new char[string.len];
				strcpy_s(string.str, string.len, str.c_str());
				exitQueue.push(string);
				str.clear();
			}

			mutex.unlock();
		}
		else
			std::this_thread::sleep_for(16ms);
	}
}

_declspec(dllexport) void __cdecl StartBison()
{
	programExecuting = true;
	currBuffer = NULL;
	yylex_init(&scan);
	bisonThread = std::thread(&BisonExecution);
	bisonThread.detach();
}

_declspec(dllexport) void __cdecl TerminateBison()
{
	programExecuting = false;
	yy_delete_buffer(currBuffer, scan);
	yylex_destroy(scan);
}

BisonString BisonAllExecution(char * stra, size_t len)
{
	currBuffer = NULL;
	yylex_init(&scan);
	BisonString string{ new char[1] {'\0'}, 1};
	std::cout << stra << std::endl;
	std::string testStr = stra;
	testStr += '\n';
	testStr += '\0';
	testStr += '\0';
	currBuffer = yy_scan_string(testStr.c_str(), scan);
	yy_switch_to_buffer(currBuffer, scan);
	if (!yyparse(scan))
	{
		string.len = str.length() + 1;
		string.str = new char[string.len];
		strcpy_s(string.str, string.len, str.c_str());
		exitQueue.push(string);
		str.clear();
	}
	yy_delete_buffer(currBuffer, scan);
	yylex_destroy(scan);
	return string;
}
