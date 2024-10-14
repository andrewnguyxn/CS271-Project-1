# Target to build and run the test executable
mytests: mytests.o sorting.o
	g++ -o mytests mytests.o sorting.o
	./mytests

# Compile mytests.cpp into an object file
mytests.o: mytests.cpp sorting.hpp
	g++ -c mytests.cpp -o mytests.o

# Target to build sorting object files (only compile sorting algorithms)
sorting.o: sorting.cpp sorting.hpp
	g++ -c sorting.cpp -o sorting.o

# Compile sorting.cpp into an object file
sorting: sorting.cpp sorting.hpp
	g++ -c sorting.cpp -o sorting.o

# Cleaning all object files and executable
clean:
	rm -f *.o mytests
