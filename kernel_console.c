/*kernel_console.c*/

#include <stdio.h>
#include <stdlib.h>

/*max login attempts*/
#define K_MAX_ATTMPS 3

/*kernel console status*/
#define KERNEL_CONSOLE_STATUS_CONNECTED 1
#define KERNEL_CONSOLE_STATUS_DISCONNECTED 0

/*print*/
void kernel_console_print( const char* message ) {
     printf( message );
}

