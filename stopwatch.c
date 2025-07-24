/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * Stopwatch - stopwatch.c
 * Contains the functions needed to
 * operate the stopwatch.
 *
 */

#include "stopwatch.h"

// (re)initialises the stopwatch
void sw_reset(struct stopwatch *sw)
{
    // TODO: create a timer enum.
    sw->state = TTYMER_STOPPED;
    sw->start_time = 0; // this stores the last start point (from sw_gettime, sw_stop). Not the original.
    sw->stopped_time = 0;
    sw->elapsed_time = 0;
}

// starts running the stopwatch
void sw_start(struct stopwatch *sw)
{
    assert(sw->state == TTYMER_STOPPED && 
            "stopwatch must be in stopped state to run");

    sw->state = TTYMER_RUNNING;

    // mark the start time
    sw->start_time = get_currenttime();
}

// pauses the stopwatch.
void sw_stop(struct stopwatch *sw)
{
    assert(sw->state == TTYMER_RUNNING && 
            "stopwatch must be in running state to stop");

    sw->state = TTYMER_STOPPED;

    // store the elapsed time
    uint64_t ct = get_currenttime();
    sw->elapsed_time += (ct - sw->start_time);
    sw->start_time = ct; 
}

// Returns the time elapsed in the stopwatch
uint64_t sw_gettime(struct stopwatch *sw)
{
    if (sw->state == TTYMER_RUNNING) {
        uint64_t ct = get_currenttime();
        sw->elapsed_time += (ct - sw->start_time);
        sw->start_time = ct; 
    }

    return sw->elapsed_time;
}

int32_t sw_getstate(struct stopwatch *sw)
{
    return sw->state;
}
