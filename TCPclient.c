#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h> //store address information

int main() {

    //create socket
    int network_socket;
    network_socket = socket( AF_INET, SOCK_STREAM, 0);

    //specify address for the socket to connect to
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; // use IPv4
    server_address.sin_port = htons(9002); //htons() converts the integer port value we give into network byte format.
    //the conversion is needed because of the structure format used
    server_address.sin_addr.s_addr = INADDR_ANY;

    int conncection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if(conncection_status == -1){
        printf("There was an error making a connection to the remote socket\n\n");
    }

    // recieve data from the server

    char server_response[256];

    recv(network_socket, &server_response, sizeof(server_response), 0);

    //printout the data that we recieved

    printf("The server sent the data: %s\n", server_response);

    //close the socket once you are done
    close(network_socket);

    return 0;
}