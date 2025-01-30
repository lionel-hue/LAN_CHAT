#include "../sys_hdrs/DECLARE.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help_pg( char* theme, char* app_name  ){

   static char response[bits];
   
   system("cls");
    printf("\033[1;%sHelp ( i )\033[0m", theme );
    printf("\n===================\n");

    printf("\033[1;%sThe server connection\033[0m\n", theme );
    printf("The server is the first connection to establish. To build a server connection use a \033[1;%svalid IP address\033[0m to search and\n", theme );
    printf("accept a client connection. Use either \033[1;%sthe default IP address \"", theme);
    printf("0.0.0.0\"\033[0m to search for any available client or  the IP address\n");
    printf("of the client if already known. \nAlways choose a port number between \033[1;%s1024\n", theme );
    printf("and 65 536\033[0m\n\n\n");


    printf("\033[1;%sThe client connection\033[0m\n", theme );
    printf("Choose this option when there is already \033[1;%san existing server\033[0m to connect to.", theme );
    printf(" To build a client connection use a \033[1;%svalid IP address of the server requested\033[0m and connect.\n", theme );

    printf("Take note that here.. \033[1;%sthe server's port number\033[0m is also required to establish a successful connection.\n\n", theme );

    printf("\n===================\n");
    printf("\033[1;%sHit\033[0m 0 to go back\n", theme );
    printf("response : ");


    printf("\033[1;%s", theme );
        fgets( response, sizeof response, stdin );
        response[ strcspn(response, "\n") ] = 0;
        printf("\033[0m");

        ( strncmp(response, "0", sizeof response -1 ) == 0 )?
        restart( app_name ):help_pg( theme, app_name );
} 