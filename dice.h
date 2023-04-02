#ifndef DICE_H
#define DICE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Simulate rolling a die.
 *
 * Parameters:
 *   sides - the number of sides on the die
 *
 * Return:
 *   the result of rolling the die
 */
unsigned int roll_die(size_t sides);

/**
 * Simulate rolling multiple dice. The results are placed in the provided
 * array.
 *
 * Parameters:
 *   dice - an array that will be filled with the rolled values
 *   sides - the number of sides on the rolled dice
 *   count - the number of dice
 */
void roll_dice(unsigned int *dice, size_t sides, size_t count);

/**
 * Print values in an array that represent dice. The values are separated by
 * spaces. No newline is printed after printing the dice.
 *
 * Parameters:
 *   dice - an array of values representing rolled dice
 *   count - the number of dice
 */
void print_dice(const unsigned int *dice, size_t count);

/**
 * Determines if an array of dice all have the same value.
 *
 * Parameters:
 *   dice - an array of values representing rolled dice
 *   count - the number of dice
 *
 * Return:
 *   true if all of the dice have the same value, false otherwise
 */
bool are_all_same(unsigned int *dice, size_t count);

/**
 * Uses a Monte Carlo method to extimate the probability of rolling dice that
 * all have the same value.
 *
 * Parameters:
 *   sides - the number of sides of each die
 *   roll_count - the number of times to roll the dice
 *
 * Return:
 *   The estimated probability that all dice will have the same value, as a
 *   number between 0 and 1
 */
double all_same_probability(size_t sides, size_t dice_count, size_t roll_count);

#endif
