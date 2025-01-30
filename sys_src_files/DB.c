#define dataBseURL "./SYSTEM/dataBase.json"

#include "../sys_hdrs/DB.h"
#include <stdlib.h>
#include <string.h>


static char* SELECT( int ref_1, char* ref_2, char* ref_3, char* ref_4 , DB *this ){


    this->fp = fopen( dataBseURL, "r" );
  
    ( this->fp == NULL )? fprintf(stderr,"error"):0;

    fread( this->buffer, 1, sizeof this->buffer, this->fp );

    this->layer_1 = cJSON_Parse( this->buffer );
    this->layer_2 = cJSON_GetArrayItem(  this->layer_1, ref_1 );
    this->layer_3 = cJSON_GetObjectItem( this->layer_2 , ref_2 );
    this->layer_4 = cJSON_GetObjectItem( this->layer_3 , ref_3 );
    this->layer_5 = cJSON_GetObjectItem( this->layer_4 , ref_4 );

    fclose( this->fp );
    return this->layer_5->valuestring;
 

}



static void UPDATE( char* new_value, int ref_1, char* ref_2, char* ref_3, char* ref_4, DB *this ){

    char* toDataBaseContainer;


    /******* 1 ******/
    this->fp = fopen( dataBseURL, "r" );

    ( this->fp == NULL )? fprintf(stderr,"error"):0;

    fread( this->buffer, 1, sizeof this->buffer, this->fp );

    this->layer_1 = cJSON_Parse( this->buffer );
    ( this->layer_1 == NULL )? fprintf(stderr,"error"):0;

    this->layer_2 = cJSON_GetArrayItem(  this->layer_1, ref_1 );
    this->layer_3 = cJSON_GetObjectItem( this->layer_2 , ref_2 );
    this->layer_4 = cJSON_GetObjectItem( this->layer_3 , ref_3 );
    cJSON_ReplaceItemInObject( this->layer_4 , ref_4, cJSON_CreateString( new_value ) );

    fclose( this->fp );



    /******* 2 *******/
    toDataBaseContainer = cJSON_Print( this->layer_1 );


    this->fp1 = fopen( dataBseURL, "w" );

    ( this->fp1 == NULL )? fprintf(stderr,"error"):0;

    fputs( toDataBaseContainer, this->fp1 );

    fclose( this->fp1 ); 

}



DB* new_DB( void ){

    DB *this;   
    this = (DB *)malloc( sizeof( DB )  );
    this->SELECT = SELECT;
    this->UPDATE = UPDATE;

    return this;
}

void del_DB( DB* this ){

    free(this);
}