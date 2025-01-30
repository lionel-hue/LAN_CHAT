#define bits 2048  //two byte of msg...
#include <winsock2.h>

// Object members and methods declarations...

typedef struct server{


    WSADATA wsa_data;
    SOCKET sockid, new_sockid;
    struct sockaddr_in server_addr, client_addr;

    int client_len;
    int end_chat;

    char *my_name;
    char msg[bits];
    char their_name[bits];


    void (*createS)          ( struct server *, char *, int, char * );
    void (*bind_listen_accept)( struct server *);
    void (*send_recvS)       ( struct server *, char *);

}server;


