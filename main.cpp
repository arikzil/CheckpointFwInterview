#include "Server.h"

int main() {
    Server sample = Server();


    sample.set_port(5003);

    /* Create a socket point */
    sample.create_socket(AF_INET, SOCK_STREAM, 0);

    sample.set_serv_add(AF_INET);

    sample.bind_socket();
    sample.listen_socket();
    sample.accept_socket();
    sample.read_socket();
    sample.write_socket();
    return 0;
}