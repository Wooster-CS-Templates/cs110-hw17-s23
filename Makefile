# This Makefile can build two different programs: roll_dice and monte_carlo.
# Both programs use the dice module. If you simply run "make" it will build the
# roll_dice program, since that is the first target in the file. You can run
# "make monte_carlo" to build the monte_carlo program.

CFLAGS=-std=c99 -Wall

roll-dice: roll_dice.o dice.o
	gcc $(CFLAGS) roll_dice.o dice.o -o roll-dice

monte-carlo: monte_carlo.o dice.o
	gcc $(CFLAGS) monte_carlo.o dice.o -o monte-carlo

function-tests: dice.h function_tests.o dice.o
	gcc $(CFLAGS) function_tests.o dice.o -o function-tests

monte_carlo.o: monte_carlo.c dice.h
	gcc $(CFLAGS) -c monte_carlo.c

roll_dice.o: roll_dice.c dice.h
	gcc $(CFLAGS) -c roll_dice.c

dice.o: dice.c dice.h
	gcc $(CFLAGS) -c dice.c

function_tests.o: dice.h tests/function_tests.c
	gcc $(CFLAGS) -c tests/function_tests.c

monte-carlo-tests: monte-carlo
	./test-monte-carlo.sh

gh-test-functions: clean function-tests
	./function-tests

gh-test-monte-carlo: clean monte-carlo monte-carlo-tests

clean:
	rm -f function-tests roll-dice monte-carlo *.o
	rm -rf tests-out
