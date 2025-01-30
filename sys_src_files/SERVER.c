#include "../sys_hdrs/SERVER.h"

#define bits 2048 // two byte of msg...
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <stdlib.h>



//Object  Methods externalised ...

static void createS(server *this, char address[bits], int portno, char* my_name){

    this->my_name = my_name;
    this->end_chat = 0;
    
    ( WSAStartup( MAKEWORD(2,2), &this->wsa_data ) == -1 )?
    perror("Failed to intialise winsock"):0;

    this->sockid = socket( AF_INET, SOCK_STREAM, 0 );
    ( this->sockid == -1 )?
    perror("Failed to create socket"):0;


    this->server_addr.sin_family      = AF_INET;
    this->server_addr.sin_addr.s_addr = inet_addr( address );
    this->server_addr.sin_port        = htons( portno );

}




static void bind_listen_accept( server *this ){
    
    ( bind( this->sockid, (struct sockaddr *) &this->server_addr, sizeof this->server_addr ) == -1 )?
    perror("failed to complete the network binding"):0;


    ( listen( this->sockid, 1 ) == -1 )?
    perror("Failed to listen for connections"):0;


    this->client_len = sizeof this->client_addr;
    this->new_sockid =  accept( this->sockid, (struct sockaddr *) &this->client_addr, &this->client_len );
    ( this->new_sockid == -1 )?
    perror("failed to accept incoming client connections..."):0;

}




static void send_recvS( server *this, char* theme ){

    (recv( this->new_sockid, this->their_name, sizeof this->their_name, 0 ) == -1 )?
    perror("Failed to receive client name"):0;

    if( send( this->new_sockid, this->my_name, sizeof this->my_name , 0 ) != -1 ){


            printf("\nConnection Established! Chat with \033[1;%s%s\033[0m.\n \033[1;%s%s\033[0m, please wait for their message!\nUse \"end_chat\" to end the discussion\n=================================\n",theme, this->their_name, theme, this->my_name );
        while( this->end_chat == 0 ){


            memset( &this->msg, '\0', sizeof this->msg );
            ( recv( this->new_sockid, this->msg, sizeof this->msg, 0 ) == -1 )?
            perror("failed to recieve message"):0;
            printf("\n\n\033[1;%s%s\033[0m : %s", theme, this->their_name, this->msg);


            memset( &this->msg, '\0', sizeof this->msg );
            printf("\n\033[1;%s\033[1;%sMe\033[0m\033[0m : %s", theme, theme, this->msg);
            fgets( this->msg, sizeof this->msg, stdin );
            this->msg[ strcspn( this->msg, "\n" ) ] = 0;
            ( send( this->new_sockid, this->msg, sizeof this->msg, 0 ) == -1 )?
            perror("failed to send message to server!..."):0;
            if ( strncmp( this->msg, "end_chat", sizeof this->msg -1 ) == 0 )this->end_chat = 1;

        }

    }else perror("Error sending your name to client");


    closesocket( this->sockid );
    WSACleanup();
}


// Object Constructor ...

server *new_server( void ){

    server *this = (server *)malloc( sizeof (server) );

    this->createS = createS;
    this->bind_listen_accept = bind_listen_accept;
    this->send_recvS = send_recvS;

    return this;
}


// Object Deconstructor...

void del_server( server *this ){
    free(this);
}