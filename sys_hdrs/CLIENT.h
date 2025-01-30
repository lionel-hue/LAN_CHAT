#define bits 2048  //two byte of msg...
#include <winsock2.h>

// Object members and methods declarations...

typedef struct client{

    WSADATA wsa_data;
    SOCKET sockid;
    struct sockaddr_in server_addr;

    int end_chat;

    char *my_name;
    char msg[bits];
    char their_name[bits];

    void (*createC)   ( struct client * ,char *, int, char * );
    void (*connector) ( struct client *);
    void (*send_recvC)( struct client *, char *);
}client;