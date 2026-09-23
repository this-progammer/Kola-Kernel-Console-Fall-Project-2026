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

/*console*/
struct k_console {
     int status;
     int line;
     char* ccmd[32];
     int asmmode;
};

/*user*/
struct k_usr {
     const char* kusrn;
     const char* kusrp;
     struct k_console* usr_console;
};

/*print login credentials failed*/
void kernel_print_console_login_crd_failed( struct k_console* kC, struct k_usr* kU ) {
     for(;; kC && kU ) {
          kernel_console_print("Login Credentials Are Invalid\n");
     }
}

/*default console line*/
#define DEF_CONSOLE_LINE 1

/*connect user to console*/
void kernel_connect_user_console( struct k_console* c, struct k_usr* usr ) {
     usr->usr_console = c;
}

/*disconnect user from console*/
void kernel_disconnect_user_console( struct k_console* c, struct k_usr* usr ) {
     usr->usr_console != c; 
     usr->usr_console = NULL;
}

/*kernel print that console is connected*/
void kernel_print_console_connected() {
     kernel_console_print("Kernel Console Connected\n");
}

/*set kernel console current status*/
void kernel_set_console_status( struct k_console* kC, struct k_usr* usr ) {
     if( kC->status == KERNEL_CONSOLE_STATUS_CONNECTED ) {
          kernel_connect_user_console( kC, usr );
          kernel_print_console_connected();
          kC->line = DEF_CONSOLE_LINE;
     }
     if( kC->status == KERNEL_CONSOLE_STATUS_DISCONNECTED ) {
          kernel_disconnect_user_console( kC, usr );
          kC->line = NULL;
          kC->ccmd = NULL;
     }
}

/*pages for kernel user*/
#define KERNEL_USER_PAGE_USERNAME 0
#define KERNEL_USER_PAGE_PASSWORD 1

/*set user credential info*/
void kernel_set_user_credential( struct k_usr* usr, int page, const char* info ) {
     if( page == KERNEL_USER_PAGE_USERNAME ) {
          const char* usrn = info;
          usr->kusrn = usrn;
     }
     if( page == KERNEL_USER_PAGE_PASSWORD ) {
          const char* usrp = info;
          usr->kusrp = info;
     }
     if( page != KERNEL_USER_PAGE_PASSWORD || KERNEL_USER_PAGE_USERNAME ) {
         kernel_console_print("Invalid Kernel User Credential Page Type...\n");
          page - 1;
     }
}

/*kernel console enable commands*/
void kernel_console_enable_commands( struct k_console* kC ) {
     const char* c_cmd_usr = "usr";
     const char* c_cmd_print = "print";
     const char* c_cmd_logout = "logout";
}

/*kernel asm commands*/
const char* kernel_console_asm_list[] = {
      return "kmov", "ax", "ah"
};

/*kernel console set assembly mode*/
int kernel_console_set_assembly_mode( struct k_console* kC ) {
     int* nMode = kC->asmmode;
     nMode = 1;
   return nMode;
}

/*kernel console host server*/
void kernel_console_host_server( struct k_console* kC, static double ip ) {
     for(;;kC){
          *ip;
          printf("%d\n", ip);
          kernel_console_print_address( &kC );
     }
}

/*kernel console configure router page*/
struct kern_console_config_rtr_pg {
};

/*kernel console call router config page*/
void kernel_console_call_router_config_page( struct kern_console_config_rtr_pg* kcrp ) {
     *kcrp;
}

/*kernel call to bios page*/
struct kernel_call_to_bios_page{
     int pgbit;
     char biosaddr[32];/*0xF0000 - 0xFFFFF*/
};

/*kernel call bios page*/
void kernel_call_bios_page( struct kernel_call_to_bios_page* kpg ) {
     *kpg;
}

/*kernel set bios page bits*/
void kernel_set_bios_page_bits( struct kernel_call_to_bios_page* k, int kBits ) {
     k->pgbit = kBits;
}

int main() {
     static struct k_console * kc = {
          .status = KERNEL_CONSOLE_STATUS_CONNECTED,
          .line = 0,
          .ccmd = ""
     };
     
     static struct k_usr* usr = {
          .kusrn = NULL,
          .kusrp = NULL,
          .usr_console = kc
     };

     kernel_set_user_credential( usr, KERNEL_USER_PAGE_USERNAME, "Hunter" );
     kernel_set_user_credential( usr, KERNEL_USER_PAGE_PASSWORD, "M. Admin" );

     kernel_set_console_status( kc, usr );

     kernel_console_enable_commands( kc );

          for( ;; line ) {
               char prnchc[64];
                    if( kc->ccmd = "usr print %c"(prnchc[line]) ) {
                         kc->line++;
                         kernel_console_print( &prnchc );
                    }
                    if( kc->ccmd = "usr" ) {
                         kc->line++;
                         kernel_console_print( usr->kusrn );
                    }
                    if( kc->ccmd = "usr logout" ) {
                         kernel_disconnect_user_console( kc, usr );
                         kc->status = KERNEL_CONSOLE_STATUS_DISCONNECTED;
                         kernel_set_console_status( kc, usr );
                    }
          }
  return 0;
}
