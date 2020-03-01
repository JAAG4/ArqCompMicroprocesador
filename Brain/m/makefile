	#### Makefile ####
	
### Tags ###
CXX = g++
CXXFLAGS = -Wall -std=c++11
INCLUDE_PATH = -I ../include/
SRC_PATH =	../src

### Rules ###

matriz.exe: matriz.o
	$(CXX) $(CXXFLAGS) $^ -o $@

matriz.o: matriz.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_PATH) $^ 

### Clean Objects and Executable Files	
clean:
	rm -rf *.o matriz.exe
	
