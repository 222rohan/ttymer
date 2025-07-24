/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * TTYMER - ttymer.h
 * Contains the general members -
 * Functions, structs, and enums
 * for other ttymer programs 
 */

#ifndef TTYMER_H 
#define TTYMER_H
/*
 * includes
 */
#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>

enum TTYMER {
    TTYMER_STOPPED,
    TTYMER_RUNNING
};

/*
 * Helper Functions
 */
int64_t get_currenttime();

#endif
