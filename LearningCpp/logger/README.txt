How to use PLOG
---------------

Steps:
1) Execute this command in the project folder:
git clone https://github.com/SergiusTheBest/plog.git

2) Include the headers in your cpp file:
#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

3) Initialize the logger
Logger& init(Severity maxSeverity, const char/wchar_t* fileName, size_t maxFileSize = 0, int maxFiles = 0);
Example:
plog::init(plog::debug, "debug.txt");

4) Use the logger in your code (long macros for this example):
PLOG_VERBOSE << "verbose";
PLOG_DEBUG << "debug";
PLOG_INFO << "info";
PLOG_WARNING << "warning";
PLOG_ERROR << "error";
PLOG_FATAL << "fatal";
PLOG_NONE << "none";

5) When compile, add plog to the path: 
g++ -I plog/include/ -Wall logger_example.cpp