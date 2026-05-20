CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: heap

heap: heap.o examheap.o
	$(CXX) $(CXXFLAGS) -o heap heap.o examheap.o

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

clean:
	rm -f *.o heap
