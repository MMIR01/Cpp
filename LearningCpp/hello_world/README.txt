1) Compile:
g++ -Wextra -Wall -c helloworld.cpp
2) Link:
g++ -o helloworld helloworld.o
3) Execute:
./helloworld

# Other compile options:
-ggdb: for debugging
-O2 -DNDEBUG: for release
-pedantic-errors: disable compiler extensions

# Warning flags:
-Wall -Weffc++ -Wextra -Wsign-conversion
-Werror: treat warnings as errors

# Select language standard:
-std=c++11, -std=c++14, -std=c++17, or -std=c++20