/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * Stopwatch - stopwatch.c
 * Contains the functions needed to
 * operate the stopwatch.
 *
 */

// TODO: add ifndefs both here and there
#include "stopwatch.h"

static int64_t get_currenttime();

// (re)initialises the stopwatch
void sw_reset(struct stopwatch *sw)
{
    // TODO: create a timer enum.
    sw->state = TTYMER_STOPPED;
    sw->start_time = 0; // this stores the last start point (from sw_gettime, sw_stop). Not the original.
    sw->stopped_time = 0;
    sw->elapsed_time = 0;
   /* FIXME: temporarily setting milli prec,
     * once options are added will fix 
     * this.
     */
    sw->precision = SW_PREC_MILLI; 
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
// FIXME: this is completely wrong
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

static int64_t get_currenttime()
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
        return (uint64_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    else 
        return 0;
}
