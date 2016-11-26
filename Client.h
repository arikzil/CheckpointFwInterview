//
// Created by arikzil on 21/09/16.
//

#ifndef CLIENTS_CLIENT_H
#define CLIENTS_CLIENT_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

class Client {
public:
    Client();

    void set_port(int port);

    void set_hostname(char *host_name);

    void set_serv_add(int family);

    void connect_socket();

    void create_socket(int family, int type, int protocol);

    void send_msg();

    void read_msg();

private:

    int sockfd;
    int portno;
    int n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
};


#endif //CLIENTS_CLIENT_H
