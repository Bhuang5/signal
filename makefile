compile: signal.o
	gcc -o signal.out signal.o

run: signal.out
	./signal.out

clean:
	rm *.out
	rm *.o
	rm *~