#include <stdio.h>
#include "../../sys_hdrs/DECLARE.h"


void settings_pg( char* theme ){

    DB *db = new_DB();
    static char my_name[bits];

    sprintf( my_name,"%s", db->SELECT( 0, "settings", "user_info", 
        "username", db ) );
    del_DB( db );


    system("cls");
    printf( "\033[1;%sSettings\033[0m", theme );
    printf("\n================\n");
    printf("My name : \033[1;%s%s\033[0m\n", theme, my_name );

    printf("\033[1;%s1\033[0m: Change name\n", theme );
    printf("\033[1;%s2\033[0m: Language settings\n", theme );
    printf("\033[1;%s3\033[0m: Theme\n", theme );
    printf("\033[1;%s0\033[0m: Back\n", theme );


    printf("response: " );
} 