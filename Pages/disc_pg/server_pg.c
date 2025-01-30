#include <stdio.h>
#include "../../sys_hdrs/DECLARE.h"

void server_pg( char*theme, char* app_name ){

    static char ip_address[bits], 
                portno[bits],  
                my_name[bits];

    DB *db = new_DB();
    sprintf( my_name,"%s", db->SELECT( 0, "settings", "user_info", 
        "username", db ) );
    del_DB( db );
    

    printf("======================\n");
    printf("Please enter your valid address to connect to a client : \033[1;%s", theme );

    fgets(ip_address, sizeof ip_address, stdin);
    ip_address[ strcspn(ip_address, "\n") ] = 0;

    printf("\033[0m\nPlease enter a valid free port number : \033[1;%s", theme );
    fgets( portno, sizeof portno, stdin);
    portno[ strcspn(portno, "\n") ] = 0;

    printf("\033[0m");


    printf("\nEstablishing connection with any nearby \033[1;%sClient\033[0m...\n", theme );

    server *srv = new_server();
    srv->createS( srv, ip_address, atoi(portno), my_name );
    srv->bind_listen_accept( srv );
    srv->send_recvS( srv, theme );

    del_server( srv );
    restart( app_name );
}