#Makefile for cs130A project01
all: main

main: main.cpp hashTable.cpp BST.cpp 
	g++ -std=c++11 -o main main.cpp hashTable.cpp BST.cpp  -lstdc++fs

clean:
	rm -f main
