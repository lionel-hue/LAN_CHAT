#include "../sys_hdrs/DECLARE.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void about_pg( char* theme, char* app_name  ){

   static char response[bits];
   
   system("cls");
    printf("\033[1;%sAbout ( ? )\033[0m", theme );
    printf("\n===================\n");

    printf("Built with pure C language by \033[1;%sDev Lionel Sisso\033[0m\n", theme );
    printf("Credits : cJSON header only library\n\n");
    printf("\033[1;%sHit\033[0m 0 to go back\n", theme );
    printf("response : ");

    printf("\033[1;%s", theme );
        fgets( response, sizeof response, stdin );
        response[ strcspn(response, "\n") ] = 0;
        printf("\033[0m");

        ( strncmp(response, "0", sizeof response -1 ) == 0 )?
        restart( app_name ):about_pg( theme, app_name );
} 