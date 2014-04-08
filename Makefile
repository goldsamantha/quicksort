
PROGRAMS = testQuickSort 
CXX = g++
CXXFLAGS = -g

all: $(PROGRAMS)


testQuickSort: randarray.o point.o testQuickSort.cpp quicksort.inl quicksort.h
	$(CXX) $(CXXFLAGS) -o testQuickSort randarray.o point.o testQuickSort.cpp


%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: clean all
