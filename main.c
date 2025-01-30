#include "./sys_hdrs/DECLARE.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main( int argc, char **argv ){
 
    char response[bits];
    char theme[bits];
    char lang[bits];



    //Play Intro video first...
    DB* d_b = new_DB();
    if( strncmp( d_b->SELECT( 0, "settings", "intro_vid", "play", d_b ), "true", 4 ) == 0 ){
        system("start vlc/vlc \"SYSTEM/INTRO.mp4\"");
        d_b->UPDATE( "false", 0, "settings", "intro_vid", "play", d_b );
    }
    del_DB( d_b );


    
    // Identifying application theme...
    DB* db = new_DB();
    sprintf(theme,  "%s", db->SELECT( 0, "settings", "app_theme", "type(d)", db ) );
    del_DB( db );


    // Test if product is activated. ..

    activation( theme, *argv );
    /************************************************************/



    //DEFAULT_PG
    default_pg( theme, *argv );

    printf("\033[1;%s", theme );
    fgets( response, sizeof response, stdin );
    response[ strcspn(response, "\n") ] = 0;
    printf("\033[0m");
    /***********************************************************/


    //DISC_PG;
    if ( response[0] == '1' && strlen(response) == 1 ){

        disc_pg( theme );

        printf("\033[1;%s", theme );
        fgets( response, sizeof response, stdin );
        response[ strcspn(response, "\n") ] = 0;
        printf("\033[0m");


        if( response[0] == '1' && strlen(response) == 1 ){

            server_pg( theme, *argv );

        }else if( response[0] == '2' && strlen(response) == 1 ){

            client_pg( theme, *argv );

        }else if( response[0] == '0' && strlen(response) == 1 ){

            restart(*argv);

        }//else 1;
    /***********************************************************/


    //SETTINGS_PG
    }else if( response[0] == '2' && strlen(response) == 1 ){

        settings_pg( theme );

        printf("\033[1;%s", theme );
        fgets( response, sizeof response, stdin );
        response[ strcspn(response, "\n") ] = 0;
        printf("\033[0m");


        if( response[0] == '1' && strlen(response) == 1 ){

            chng_nm_pg( theme, *argv );


        }else if( response[0] == '2' && strlen(response) == 1 ){

            /*lang_pg( theme, *argv, lang );*/restart(*argv);


        }else if( response[0] == '3' && strlen(response) == 1 ){

            theme_pg( theme, *argv );

        }else if( response[0] == '0' && strlen(response) == 1 ){

            restart(*argv);

        }//else 1;
    /***********************************************************/


    //HELP_PG
    }else if( response[0] == '3' && strlen(response) == 1 ){

        help_pg( theme, *argv );
    /***********************************************************/



    //ABOUT_PG
    }else if( response[0] == '4' && strlen(response) == 1 ){

        about_pg( theme, *argv );
    /***********************************************************/


    //EXIT APP
    }else if( response[0] == '0' && strlen(response) == 1 ){

        system("cls && exit");
    /***********************************************************/

        
    }else restart( *argv );

}