compile: driver.o sieve.o
	gcc driver.o sieve.o -lm

run:
	./a.out $(args)

clean:
	-rm -f /a.out *.o

driver.o:
	gcc -c driver.c

sieve.o:
	gcc -c sieve.c
