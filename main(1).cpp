
#include "Client.h"

int main() {
    Client sample = Client();

    /* set the port */
    sample.set_port(5003);

    /* Create a socket point */
    sample.create_socket(AF_INET, SOCK_STREAM, 0);

    /* set the hostname  */
    char hostname[10] = "localhost";

    sample.set_hostname(hostname);

    /* set the server address  */
    sample.set_serv_add(AF_INET);

    /* connects to the server*/
    sample.connect_socket();

    /* sends a message*/
    sample.send_msg();

    /* reads a message*/
    sample.read_msg();

    return 0;
}