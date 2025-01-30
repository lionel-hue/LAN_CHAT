#include <stdio.h>
#include "../../sys_hdrs/DECLARE.h"

void client_pg( char* theme, char* app_name ){

    static char ip_address[bits], 
                portno[bits], 
                my_name[bits];

    DB *db = new_DB();
    sprintf( my_name,"%s", db->SELECT( 0, "settings", "user_info", 
        "username", db ) );
    del_DB( db );


    printf("======================\n");
    printf("Please enter a valid local server Ip address : \033[1;%s", theme );

    fgets(ip_address, sizeof ip_address, stdin);
    ip_address[ strcspn(ip_address, "\n") ] = 0;

    printf("\033[0m\nPlease enter server's port number : \033[1;%s", theme );
    fgets( portno, sizeof portno, stdin);
    portno[ strcspn(portno, "\n") ] = 0;

    printf("\033[0m");


    printf("Establishing connection with this nearby \033[1;%sServer\033[0m...\n", theme );

    client *cli = new_client();
    cli->createC( cli, ip_address, atoi(portno), my_name );
    cli->connector( cli );
    cli->send_recvC( cli, theme );

    del_client( cli );
    restart( app_name );
}