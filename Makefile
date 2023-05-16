#!make -f

#CXX=clang++-9 
CXX=gcc
CXXFLAGS= -Wall -g

HEADERS=AdptArray.h book.h Person.h
OBJECTS=AdptArray.o book.o Person.o
SOURCES=AdptArray.c book.c Person.c

run: demo mydemo
	# ./$^
	./demo
	./mydemo

mem_test: demo mydemo
	# valgrind ./$^
	valgrind ./demo
	valgrind ./mydemo

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

mydemo: MyDemo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o mydemo

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo mydemo
