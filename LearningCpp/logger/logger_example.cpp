/***********************************
 * MMIR01. How to use a logger.
 * In this case, we are using PLOG
************************************/

#include <iostream>
#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

int main()
{
	std::cout << "PLOG EXAMPLE\n";
    
    //Example 1. DEBUG LEVEL
    plog::init(plog::debug, "debug.txt");

    PLOG_VERBOSE << "verbose message is not shown";
    PLOG_DEBUG << "debug message is shown";
    PLOG_INFO << "info message is shown";
    PLOG_WARNING << "warning message is shown";
    PLOG_ERROR << "error message is shown";
	
    //Example 2. INFO LEVEL
    /*
    plog::init(plog::info, "info.txt");

    PLOG_VERBOSE << "verbose message is not shown";
    PLOG_DEBUG << "debug message is not shown";
    PLOG_INFO << "info message is shown";
    PLOG_WARNING << "warning message is shown";
    PLOG_ERROR << "error message is shown";
    */

	return 0;
}