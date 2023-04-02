/**
 * This program simulates rolling a number of dice. The number of dice and the
 * number of sides on the dice are provided on the command line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dice.h"


int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <sides per die> <dice count>\n", argv[0]);
        return 1;
    }

    // Since this program will be using the rand() function to simulate rolling
    // dice, we need to seed the random number generator. We use the time as
    // the seed so that we get different rolls each time we run the program
    srand(time(NULL));

    // The function atoi() (ASCII to integer) converts a string to an integer.
    // Here we use atoi() to convert the command line argument values to
    // integers.
    size_t sides = atoi(argv[1]);
    size_t dice_count = atoi(argv[2]);

    // This array will store the values of the dice
    unsigned int dice[dice_count];

    // The roll_dice() function sets the values in the dice array to random
    // values
    roll_dice(dice, sides, dice_count);

    printf("Rolled %zu %zu-sided dice:\n", dice_count, sides);
    print_dice(dice, dice_count);
    printf("\n");

    return 0;
}
