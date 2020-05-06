CFLAGS=-Wall -O2 -ansi
fib: fib.o bmp.o timing.o main_fib.o
		$(CXX) -o fib $?
runall:
		./fib 7 10 10 10 100 100 fib7.bmp
		./fib 9 10 10 10 1000 1000 fib9.bmp
		./fib 25 10 10 5 5000 5000 fib25.bmp
		./fib 26 10 10 5 7000 7000 fib26.bmp
clean:
		@rm -rf fib *.o *bmp
	