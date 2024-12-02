#include <sys/socket.h>   
#include <stdio.h>        
#include <arpa/inet.h>    
#include <poll.h>         
#include <unistd.h>       

int main() {
    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET for IPv4, SOCK_STREAM for TCP

    // Define the server's address and port
    struct sockaddr_in address = {
        AF_INET,             // Address family (IPv4)
        htons(8080),         // Port number (converted to network byte order)
        0                    // Bind to any IP address
    };

    // Bind the socket to the specified address and port
    bind(sockfd, &address, sizeof(address));

    // Set the socket to listen for incoming connections
    listen(sockfd, 10); // Listen for up to 10 simultaneous connections

    // Accept an incoming connection from a client
    int clientfd = accept(sockfd, 0, 0); // Blocks until a client connects

    // Set up file descriptors for polling
    // fd[0]: Standard input (stdin), fd[1]: Connected client socket
    struct pollfd fds[2] = {
        {
            0,          // File descriptor for stdin
            POLLIN,     // Check if data is ready to be read
            0           // Events (initially 0)
        },
        {
            clientfd,   // File descriptor for the client
            POLLIN,     // Check if data is ready to be read
            0           // Events (initially 0)
        }
    };

    // Infinite loop to handle communication
    for (;;) {
        char buffer[256] = { 0 }; // Buffer to hold data

        // Wait for an event on stdin or client socket
        poll(fds, 2, 50000); // Timeout: 50,000 ms (50 seconds)

        // Step 8: Check if there's input from stdin
        if (fds[0].revents & POLLIN) {
            read(0, buffer, 255);             // Read input from stdin
            send(clientfd, buffer, 255, 0);  // Send the input to the client
        } 
        // Step 9: Check if there's data from the client
        else if (fds[1].revents & POLLIN) {
            if (recv(clientfd, buffer, 255, 0) == 0) { 
                // If client disconnects, end the server
                return 0;
            }

            // Print the client's message to the console
            printf("%s\n", buffer);
        }
    }

    return 0;
}
