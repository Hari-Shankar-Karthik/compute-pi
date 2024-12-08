all: main

main: main.cpp
	g++ -Wall -std=c++20 -O3 $< -o $@