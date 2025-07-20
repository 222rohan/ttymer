/*
 * 2025 Rohan Shenoy - @222rohan
 *
 * Main Driver program for ttymer
 *
 * Contains the ncurses window 
 * implementation for TUI
 *
 * TODO: Move TUI to separate graphics.h/.c
 * in the future so we can make stopwatch, timer, clock, etc..
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>

#include "stopwatch.h"

// TODO: move TUI related functions outside main
int main(int argc, char *argv[])
{
    // initialise stopwatch  
    struct stopwatch sw;
    sw_reset(&sw);

    // init ncurses
    initscr();
    noecho();
    nodelay(stdscr, true);
 
    char ch;
    int tui_running = true;

    // main loop for the stopwatch
    while (tui_running) {
        ch = getch();

        switch (ch) {
            case SW_KEY_QUIT:
                tui_running = false; 
                break;

            case SW_KEY_RESET:
                sw_reset(&sw);
                break;

            case SW_KEY_TOGGLE_STATE:
                sw_getstate(&sw) == TTYMER_RUNNING ?
                    sw_stop(&sw) :
                    sw_start(&sw);
                break;
        
            // TODO: add laps

            default: 
                // do nothing
        }

        clear();
        int64_t sw_time = sw_gettime(&sw);
        printw("stopwatch: %lu", sw_time);
        refresh();

        usleep(SW_PREC_MILLI);
    }
    
    // destroy ncurses window
    endwin();

    return EXIT_SUCCESS;
}
