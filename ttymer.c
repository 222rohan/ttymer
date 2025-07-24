/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * TTYMER - ttymer.c
 * Function definitions for the ttymer header
 */

#include "ttymer.h"

int64_t get_currenttime()
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
        return (uint64_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    else 
        return 0;
}
