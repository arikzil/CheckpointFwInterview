//
// Created by arikzil on 21/09/16.
//

#include "Server.h"
//
// Created by arikzil on 21/09/16.
//

Server::Server() {

};

void Server::set_port(int port) {
    this->portno = port;
};

void Server::create_socket(int family, int type, int protocol) {
    sockfd = socket(family, type, protocol);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
};


void Server::set_serv_add(int family) {
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = family;//IPv4
    serv_addr.sin_addr.s_addr = INADDR_ANY;//any address
    serv_addr.sin_port = htons(portno);//host to server
};


void Server::bind_socket() {
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
};

void Server::read_socket(){
    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);
}

void Server::write_socket(){
    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);
}





void Server::listen_socket() {
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
};

void Server::accept_socket() {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
};

