# Chat Server Using Sockets in C  

This branch (`chat-server`) contains a simple implementation of a chat server using sockets in C. It demonstrates communication between a server and a client over TCP, making it an ideal learning resource for understanding socket programming concepts.

---

## Features  
- TCP-based communication using sockets.  
- Handles both server input and client messages via `poll`.  
- Designed to showcase fundamental networking concepts.  

---

## Prerequisites  
- GCC or any compatible C compiler.  
- Linux environment for socket programming (or WSL on Windows).  

---

## How to Run  

1. **Switch to the `chat-server` Branch**  
   ```bash
   git checkout chat-server
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

4. **Client side implementation coming soon**

---

## How It Works  
- The server listens on port `8080` for incoming client connections.  
- Messages entered on the server's terminal (`stdin`) are sent to the connected client.  
- Messages from the client are displayed on the server console.  

---

## Branch Information  
This branch is dedicated to the **chat-server** implementation as part of the ongoing **socket-programming** repository. For other examples or extensions, check out the main branch.  

---

## License  
This project is open-source and available under the MIT License.  