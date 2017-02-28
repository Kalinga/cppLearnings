#include <stdio.h>

int main(void)
{
    return 0;
}

// gcc memory_layout.c -o memory_layout

// size memory_layout
// text	   data	    bss	    dec	    hex	filename
// 1115	    552	      8	   1675	    68b	memory_layout

// text: Code + maybe any read-only data
// data: Initialized static/global data
// bss:  Block started with storage, un initialized data in code and initialized to 0/NULL by Kernel
// dec:  Total size in decimal
// hex:  Total size in Hex
// filename: Object file name


// For runtime Stack and Heap usage
// Look at /proc/$PID/maps and smaps.
