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

/*kernel console print address*/
void kernel_console_print_address( void* kcpa ) {
     printf("%p", &kcpa);
}

struct k_console {
     int status;
     int line;
     char* ccmd[32];
};

struct k_usr {
     const char* kusrn;
     const char* kusrp;
     struct k_console* usr_console;
};

void kernel_print_console_login_crd_failed( struct k_console* kC, struct k_usr* kU ) {
     for(;; kC && kU ) {
          kernel_console_print("Login Credentials Are Invalid\n");
     }
}

#define DEF_CONSOLE_LINE 1

void kernel_connect_user_console( struct k_console* c, struct k_usr* usr ) {
     usr->usr_console = c;
}

void kernel_disconnect_user_console( struct k_console* c, struct k_usr* usr ) {
     usr->usr_console != c; usr->usr_console = NULL;
}

void kernel_print_console_connected() {
     kernel_console_print("Kernel Console Connected\n");
}

void kernel_set_console_status( struct k_console* kC, struct k_usr* usr ) {
     if( kC->status == KERNEL_CONSOLE_STATUS_CONNECTED ) {
          kernel_connect_user_console( kC, usr );
          kC->line = DEF_CONSOLE_LINE;
     }
     if( kC->status == KERNEL_CONSOLE_STATUS_DISCONNECTED ) {
          kernel_disconnect_user_console( kC, usr );
          kC->line = NULL;
          kC->ccmd = NULL;
     }
}
