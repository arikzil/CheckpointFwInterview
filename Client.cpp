//
// Created by arikzil on 21/09/16.
//

#include <iostream>
#include "Client.h"

Client::Client() {

};

void Client::set_port(int port) {
    this->portno = port;
};

void Client::create_socket(int family, int type, int protocol) {
    sockfd = socket(family, type, protocol);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

};


void Client::set_hostname(char *host_name) {
    this->server = gethostbyname(host_name);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
};

void Client::set_serv_add(int family) {

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = family;
    bcopy((char *) server->h_addr,
          (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
};


void Client::connect_socket() {
    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
};


void Client::send_msg() {
/* Now ask for a message from the user, this message
* will be read by server
*/
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
};


void Client::read_msg() {

    /* Now read server response */
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
};
