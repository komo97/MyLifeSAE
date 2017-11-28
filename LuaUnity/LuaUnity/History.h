#pragma once
#include"Page.h"
#include<map>

class History
{
public:
	std::map<int,Page> pages;
	static History * getPtr();
	~History();
private:
	static History * ptr;
	History();

};

