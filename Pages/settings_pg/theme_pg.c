#include <stdio.h>
#include <stdlib.h>
#include "../../sys_hdrs/DECLARE.h"


void theme_pg( char* theme, char* app_name ){


    printf("\n===================\n");
    printf("Select your preferred theme\n\n");

    printf("\033[1;%s1\033[0m: \033[1;30mLight Ash\033[0m\n", theme );
    printf("\033[1;%s2\033[0m: \033[1;31mDeep Red\033[0m\n", theme );
    printf("\033[1;%s3\033[0m: \033[1;32mDark Green\033[0m\n", theme );

    printf("\033[1;%s4\033[0m: \033[1;33mLight Brown\033[0m\n", theme );
    printf("\033[1;%s5\033[0m: \033[1;34mDeep Blue\033[0m\n", theme );
    printf("\033[1;%s6\033[0m: \033[1;35mPurple\033[0m\n", theme );
    printf("\033[1;%s7\033[0m: \033[1;36mAqua Blue\033[0m\n", theme );

    printf("\033[1;%s0\033[0m: Back\n\n", theme );

    printf("response: \033[1;%s", theme );
    fgets( theme, sizeof theme, stdin );
    theme[ strcspn(theme, "\n") ] = 0;
    printf("\033[0m");



     DB *db = new_DB();

     if( strncmp( theme, "1", 1 ) == 0 ){

        db->UPDATE("Light Ash", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("30m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


     }else if( strncmp( theme, "2", 1 ) == 0 ){
        db->UPDATE("Deep Red", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("31m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


     }else if( strncmp( theme, "3", 1 ) == 0 ){
        db->UPDATE("Dark Green", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("32m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


    }else if( strncmp( theme, "4", 1 ) == 0 ){
        db->UPDATE("Light Brown", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("33m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


    }else if( strncmp( theme, "5", 1 ) == 0 ){
        db->UPDATE("Deep Blue", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("34m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


    }else if( strncmp( theme, "6", 1 ) == 0 ){
        db->UPDATE("Purple", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("35m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


    }else if( strncmp( theme, "7", 1 ) == 0 ){
        db->UPDATE("Aqua Blue", 0, "settings", "app_theme", "type(s)", db);
        db->UPDATE("36m", 0, "settings", "app_theme", "type(d)", db);
        restart( app_name );


    }else if( strncmp( theme, "0", 1 ) == 0 ){
        restart( app_name );


    }else restart( app_name );
    del_DB( db );

} 