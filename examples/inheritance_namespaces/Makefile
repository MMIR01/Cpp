# Makefile for inheritance namespace example

# Main target
CC = g++
FLAGS = -Wall

example: main.o baseClassFolder/file1.o derivedClassFolder/file2.o
	${CC} ${FLAGS} -o example main.o baseClassFolder/file1.o derivedClassFolder/file2.o

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp

file1.o: baseClassFolder/file1.cpp
	${CC} ${FLAGS} -c baseClassFolder/file1.cpp

file2.o: derivedClassFolder/file2.cpp
	${CC} ${FLAGS} -c derivedClassFolder/file2.cpp
clean:
	find . -type f -name "*.o" -exec rm -f "{}" \;

# Note
# We can see sometimes ".h" files being fed directly to the compiler.
# From: https://stackoverflow.com/questions/17416719/do-i-need-to-compile-the-header-files-in-a-c-program
# Many compilers will treat files differently depending on the file name extension. 
# "GCC has special treatment for files with .h extension when they are supplied to 
# the compiler as command-line arguments. Instead of treating it as a regular translation 
# unit, GCC creates a precompiled header file for that .h file."

# Example:
# file2.o: derivedClassFolder/file2.cpp baseClassFolder/file1.h
#	${CC} ${FLAGS} -c derivedClassFolder/file2.cpp