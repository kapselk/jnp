CXX = g++
CXXFLAGS = -Wall -Wpedantic -g -Werror

prog: prog.o fib.o
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm fib.o prog.o prog

fib.o: fib.h