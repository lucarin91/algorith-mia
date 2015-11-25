CXX = g++
CXXFLAGS = -std=c++11 -O3

.PHONY: all_build build clean

all_build: build main

main: main.cpp build/bubbleSort.o build/gnomeSort.o build/heapSort.o build/insertionSort.o build/introSort.o build/quickSort.o
	$(CXX) $^ $(CXXFLAGS) -o $@

build/%.o: %.cpp ComparisonSort.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

build:
	mkdir -p build

clean:
	rm -Rvf build main.out
