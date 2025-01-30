#define bits 2048 // one byte of msg...

#include "./CLIENT.h"
#include "./SERVER.h"

#include "./DB.h"


//all functions declarations...

//void main( void );  //I think this is really bad ...did'nt work
void activation( char*, char* );

void default_pg( char*, char*);

void disc_pg( char* );
void server_pg( char*, char* );
void client_pg( char*, char* );
void help_pg( char*, char* );
void about_pg( char*, char* );

void settings_pg( char* );
void chng_nm_pg( char*, char* );
void lang_pg( char*, char*, char* );
void theme_pg( char*, char* );



//server and client constructors declarations 
server *new_server( void );
void del_server( server* );

client *new_client( void );
void del_client( client* );

//Data base Constructor and Deconstructor 
DB* new_DB( void );
void del_DB( DB* );


//restart declaration
void restart( char* );