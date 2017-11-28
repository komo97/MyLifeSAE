#include "History.h"


History * History::ptr;
	
History::History()
{
}


History::~History()
{
}

History * History::getPtr()
{

	if (ptr == nullptr)
	{
		ptr = new History();
	}
	return ptr;
}