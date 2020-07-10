PROG_LOCATION = ../../src/brain


CXXFLAGS +=  -I$(PROG_LOCATION) -std=c++11 -DUNIT_TEST

CXX = g++

.PHONY: run clean

tests: *.cpp $(PROG_LOCATION)/Brain.o
	$(CXX) $(CXXFLAGS) -I$(PROG_LOCATION) $^ -lCppUTest -o tests.bin

run: tests
	- ./tests.bin

clean:
	rm -f tests.bin

