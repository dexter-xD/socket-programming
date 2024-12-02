# Chat Server Using Sockets in C  

This project demonstrates a simple chat server implemented in C using sockets. The server handles communication with a single client, relaying messages between the server and the client.

---

## Features  
- TCP-based chat server using sockets.  
- Uses `poll` for handling input from both the client and server's standard input.  
- Lightweight and straightforward implementation for learning purposes.  

---

## Prerequisites  
- GCC or any compatible C compiler.  
- Linux environment for socket programming (or WSL on Windows).  

---

## How to Run  

1. **Clone the Repository**  
   ```bash
   git clone <repository-url>
   cd <repository-folder>
   ```

2. **Compile the Code**  
   ```bash
   gcc -o server server.c
   ```

3. **Run the Server**  
   ```bash
   ./server
   ```
   The server will start and listen on port `8080`.  

---

## How It Works  
- The server listens on port `8080` for incoming client connections.  
- Messages from the server's input (`stdin`) are sent to the connected client.  
- Messages from the client are displayed on the server console.  

---

## License  
This project is open-source and available under the MIT License.  