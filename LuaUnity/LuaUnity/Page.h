#pragma once
#include <string>
#include <vector>
#include "Answer.h"

using namespace std;

class Page
{
public:
	std::vector<string> texts;
	std::vector<Answer> answers;
public:
	Page();
	~Page();
};

