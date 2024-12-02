#include <sys/socket.h> // For socket functions
#include <stdio.h>      // For printf and standard I/O functions
#include <arpa/inet.h>  // For sockaddr_in and htons
#include <poll.h>       // For poll function
#include <unistd.h>     // For read and close

int main() {
    // Create a TCP socket (SOCK_STREAM)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address we want to connect to
    struct sockaddr_in address = {
        AF_INET,        // IPv4 address family
        htons(8080),    // Port number (convert to network byte order)
        0               // Automatically use the correct IP for localhost
    };

    // Connect to the server at the specified address
    connect(sockfd, &address, sizeof(address));

    // Define two `pollfd` structures to monitor:
    // 1. Standard input (stdin) - File descriptor 0
    // 2. The socket (sockfd) for server messages
    struct pollfd fds[2] = {
        {
            0,          // File descriptor for stdin
            POLLIN,     // Check for incoming data
            0           // Event flags (set by poll)
        },
        {
            sockfd,     // File descriptor for the socket
            POLLIN,     // Check for incoming data
            0           // Event flags (set by poll)
        }
    };

    // Infinite loop to handle user input and server messages
    for (;;) {
        char buffer[256] = { 0 }; // Buffer to hold input or server data

        // Monitor both stdin and the socket for events
        poll(fds, 2, 50000); // Wait up to 50 seconds for an event

        // Check if there is input from stdin (user typing)
        if (fds[0].revents & POLLIN) {
            read(0, buffer, 255);        // Read input from stdin
            send(sockfd, buffer, 255, 0); // Send the input to the server
        }
        // Check if there is data from the server
        else if (fds[1].revents & POLLIN) {
            // If the server closes the connection, exit
            if (recv(sockfd, buffer, 255, 0) == 0) {
                return 0;
            }

            // Print the received message from the server
            printf("%s\n", buffer);
        }
    }

    return 0; // Exit the program (never reached due to infinite loop)
}
