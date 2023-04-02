#include "dice.h"


unsigned int roll_die(size_t sides) {
    return rand() % sides + 1;
}


void roll_dice(unsigned int *dice, size_t sides, size_t count) {
    for (size_t i = 0; i < count; i++) {
        dice[i] = roll_die(sides);
    }
}


void print_dice(const unsigned int *dice, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%u", dice[i]);
        if (i < count - 1) {
            putchar(' ');
        }
    }
}


// Implement the 2 new functions here
