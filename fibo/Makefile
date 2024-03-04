CXX = g++
CXXFLAGS = -Wall -Wpedantic -g -Werror

prog: prog.o fibo.o
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm fibo.o prog.o prog

fib.o: fib.h