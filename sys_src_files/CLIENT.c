#include "../sys_hdrs/CLIENT.h"

#define bits 2048  //two byte of msg...
#include <stdio.h>
#include <string.h>
#include <winsock2.h>



//Object  Methods externalised ...

static void createC( client *this, char address[bits], int portno, char* my_name ){

    this->my_name = my_name;
    this->end_chat= 0;

    ( WSAStartup( MAKEWORD( 2,2 ), &this->wsa_data ) == -1 )?
    perror("Failed to intialise socket"):0;

    this->sockid = socket( AF_INET, SOCK_STREAM, 0 );

    this->server_addr.sin_family      = AF_INET;
    this->server_addr.sin_addr.s_addr = inet_addr( address );
    this->server_addr.sin_port        = htons( portno );
}



static void connector( client *this ){

    ( connect( this->sockid, (struct sockaddr *) &this->server_addr, sizeof this->server_addr ) == -1 )?
    perror("Failed to connect to this server"):0;
}




static void send_recvC( client *this, char* theme ){

    ( send(this->sockid, this->my_name , sizeof this->my_name , 0 ) == -1 )?
        perror("Error sending your name to server"):0;



    if( recv(this->sockid, this->their_name, sizeof this->their_name, 0 ) != -1 ){

            printf("\nConnection Established, Chat with \033[1;%s%s\033[0m\nPlease  \033[1;%s%s\033[0m, send a message!\nUse \"end_chat\" to end the discussion\n=================================\n",theme, this->their_name, theme, this->my_name );
        while( this->end_chat == 0 ){


            memset( &this->msg, '\0', sizeof this->msg );
            printf("\n\n\033[1;%sMe\033[0m : %s", theme, this->msg);
            fgets( this->msg, sizeof this->msg, stdin );
            this->msg[ strcspn(this->msg, "\n") ] = 0;
            ( send( this->sockid, this->msg, sizeof this->msg, 0 ) == -1 )?
            perror("failed to send message to server!..."):0;
            if ( strncmp( this->msg, "end_chat", sizeof this->msg -1 ) == 0 ) this->end_chat = 1;


            memset( &this->msg, '\0', sizeof this->msg );
            ( recv( this->sockid, this->msg, sizeof this->msg, 0 ) == -1 )?
            perror("failed to recieve message"):0;
            printf("\033[1;%s%s\033[0m : %s",theme, this->their_name, this->msg);

        }
        
    }else perror("Failed to receive server's name"); 


    closesocket( this->sockid );
    WSACleanup();
}


// Object Constructor 
client *new_client( void ){

    client *this = (client *)malloc( sizeof( client ) );

    this->createC = createC;
    this->connector = connector;
    this->send_recvC = send_recvC;

    return this;
}
 

// Object Deconstructor...
void del_client( client *this ){
    free(this);
}