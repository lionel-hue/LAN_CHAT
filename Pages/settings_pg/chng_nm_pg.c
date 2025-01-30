#include <stdio.h>
#include <stdlib.h>
#include "../../sys_hdrs/DECLARE.h"


void chng_nm_pg( char* theme, char* app_name ){

    DB *db = new_DB();
    char my_name[bits];
    char response[bits]; 

    sprintf( my_name, "%s", db->SELECT(0, "settings", "user_info", "username", db) );


    printf("\n===================\n");
    printf("Please enter your new name : ");

    printf("\033[1;%s", theme );
    fgets( my_name, sizeof my_name, stdin );
    my_name[ strcspn(my_name, "\n") ] = 0;
    printf("\033[0m");


    db->UPDATE( my_name, 0, "settings", "user_info", "username", db );
    printf("your new name has been changed succesfully to \033[1;%s%s\033[0m.\n", theme, my_name );
    del_DB( db );


    printf("\n===================\n");
    printf("\033[1;%sHit\033[0m 0 to go back\n", theme );
    printf("response : ");

    printf("\033[1;%s", theme );
    fgets( response, sizeof response, stdin );
    response[ strcspn(response, "\n") ] = 0;
    printf("\033[0m");

    ( strncmp(response, "0", sizeof response -1 ) == 0 )?
    restart( app_name ):restart( app_name );

} 