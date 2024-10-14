driver: mytests.o
	g++ -o driver mytests.o
	
listdriver.o: mytests.cpp sorting.hpp sorting.cpp
	g++ -c mytests.cpp