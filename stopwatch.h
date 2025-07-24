/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * Stopwatch - stopwatch.h
 * Contains the declarations, enums
 * and constants needed for 
 * the stopwatch
 *
 */

#ifndef STOPWATCH_H
#define STOPWATCH_H
/*
 * includes
 */
#include "ttymer.h"

/*
 * Stopwatch Variables
 * 
 */
enum SW_VARS {
    SW_PREC_MILLI = 1000,

    SW_KEY_QUIT = 'q',
    SW_KEY_RESET = 'r',
    SW_KEY_TOGGLE_STATE = ' ',
    SW_KEY_LAP = 'l'
};

/*
 * Stopwatch struct
 */
struct stopwatch {
    uint64_t start_time;
    uint64_t stopped_time;
    uint64_t elapsed_time;
    int32_t state;
    /*
     * Not sure if this will ever 
     * be used, but maybe in the 
     * future..
     */
    // int32_t precision;
};

/*
 * Functions to control 
 * the stopwatch.
 */
void sw_reset(struct stopwatch *sw);
void sw_start(struct stopwatch *sw);
void sw_stop(struct stopwatch *sw);

/*
 * Getter functions
 */
uint64_t sw_gettime(struct stopwatch *sw);
int32_t sw_getstate(struct stopwatch *sw);

#endif
