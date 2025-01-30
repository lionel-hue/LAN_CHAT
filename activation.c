#include <stdio.h>
#include <stdlib.h>
#include "./sys_hdrs/DECLARE.h"

void activation( char* theme, char* app_name ){

    int startups_int;
    char startups_char[bits];

    char response[bits];
    char product_key[bits];


    DB* db = new_DB();
    //producut  key generator; 
    //Product key = app theme in \033 ascii + username + lang + max_startups

    strncat( product_key,
             db->SELECT( 0, "settings", "app_theme", "type(d)", db ),
             sizeof db->SELECT( 0, "settings", "app_theme", "type(d)", db ) );

    strncat( product_key,
             db->SELECT( 0, "settings", "user_info", "username", db ),
             sizeof db->SELECT( 0, "settings", "user_info", "username", db ) );

    strncat( product_key,
             db->SELECT( 0, "settings", "activation", "max_startups", db ),
             sizeof db->SELECT( 0, "settings", "activation", "max_startups", db ) );

    strncat( product_key,
             db->SELECT( 0, "settings", "language", "type", db ),
             sizeof db->SELECT( 0, "settings", "language", "type", db ) );


    db->UPDATE( product_key, 0, "settings", "activation", "product_key", db );




    //Check if number of startups > 20 to disable application and demand activation ... 
    startups_int = atoi( db->SELECT( 0, "settings", "activation", "startups", db ) );

    startups_int++;


    snprintf( startups_char, sizeof startups_char, "%d", startups_int );

    db->UPDATE( startups_char , 0, "settings", "activation", "startups", db );



    if ( startups_int > atoi( db->SELECT( 0, "settings", "activation", "max_startups", db ) ) ){

        if( strncmp( db->SELECT( 0, "settings", "activation", "is_activated", db ), "false", 5 ) == 0 ){


            printf("You will need to activate your software to continue.\n");
            printf("\033[1;%sPlease\033[0m enter your product key :", theme );

            printf("\033[1;%s", theme );
            fgets( response, sizeof response, stdin );
            response[ strcspn(response, "\n") ] = 0;
            printf("\033[0m");

            ( strncmp( db->SELECT( 0, "settings", "activation", "product_key", db ), response, sizeof response ) == 0 )?
            db->UPDATE( "true", 0, "settings", "activation", "is_activated", db ): restart( app_name );
        }

    }
    del_DB( db );

}