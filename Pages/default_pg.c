#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sys_hdrs/DECLARE.h"


void default_pg( char* theme, char* app_name ){ 

    DB* db = new_DB();
    static char my_name[bits];


    if( strncmp( db->SELECT( 0, "settings", "user_info", 
        "is_set", db ), "false", 4  ) == 0 )
    {

        system("cls");
        printf("My name is... ");

        printf("\033[1;%s", theme );
        fgets( my_name, sizeof my_name, stdin );
        my_name[ strcspn(my_name, "\n") ] = 0;
        printf("\033[0m");

        db->UPDATE( my_name, 0, "settings", "user_info", "username", db );

        db->UPDATE( "true", 0, "settings", "user_info", "is_set", db );
        restart( app_name );

    }

    del_DB( db );



    system("cls");
    printf( "Welcome to ~ \033[1;%sLAN_CHAT!\033[0m\n", theme );
    printf("\n======================\n\n");

    printf("Choose an Option" );
    printf("\n================\n");

    printf("\033[1;%s1\033[0m: Start a LAN discussion\n", theme );
    printf("\033[1;%s2\033[0m: Settings\n", theme );
    printf("\033[1;%s3\033[0m: Help\n", theme );
    printf("\033[1;%s4\033[0m: About\n", theme );
    printf("\033[1;%s0\033[0m: Exit\n", theme );

    printf("response: " );

}