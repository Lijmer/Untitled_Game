#include "Exit.h"
#include <stdlib.h>

namespace Exit
{
	bool running = true;
	int returnValue = 0;

	void Exit(int returnValue)
	{
		Exit::returnValue = returnValue;
		running = false;
	}

	void Terminate(int returnValue)
	{
		#ifdef MYDEBUG
		exit(returnValue);
		#else
		Exit(returnValue);
		#endif
	}

	bool GetRunning()
	{
		return running;
	}
}