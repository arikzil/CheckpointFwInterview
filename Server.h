//
// Created by arikzil on 21/09/16.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
//#include <cstdlib>
#include <string.h>
#include <stdlib.h>

class Server {
private:
    int sockfd;
    int newsockfd;
    int portno;
    int clilen;

    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;


public:
    Server();

    void create_socket(int family, int type, int protocol);

    void set_serv_add(int family);

    void set_port(int port);

    void bind_socket();

    void listen_socket();

    void read_socket();

    void write_socket();

    void accept_socket();
};


#endif //UNTITLED_SERVER_H
