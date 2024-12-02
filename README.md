# Chat Server Using Sockets in C  

This branch (`chat-server`) contains a simple implementation of a chat server and client using sockets in C. It demonstrates communication between a server and a client over TCP, making it an ideal learning resource for understanding socket programming concepts.

---

## Features  
- TCP-based communication using sockets.  
- Handles both server input and client messages via `poll`.  
- Client implementation for sending and receiving messages.  
- Designed to showcase fundamental networking concepts.  

---

## Prerequisites  
- GCC or any compatible C compiler.  
- Linux environment for socket programming (or WSL on Windows).  

---

## How to Run  

### 1. **Switch to the `chat-server` Branch**  
   ```bash
   git checkout chat-server
   ```

### 2. **Compile the Code**  
- Compile the server code:  
   ```bash
   gcc -o server server.c
   ```
- Compile the client code:  
   ```bash
   gcc -o client client.c
   ```

### 3. **Run the Server**  
   ```bash
   ./server
   ```  
   The server will start and listen on port `8080`.  

### 4. **Run the Client**  
   In a separate terminal, execute:  
   ```bash
   ./client
   ```  
   The client will connect to the server on port `8080`.  

### 5. **Start Chatting**  
- Messages entered in the server's terminal (`stdin`) will be sent to the client.  
- Messages entered in the client's terminal (`stdin`) will be sent to the server.  
- Both messages will appear on the respective terminals.  

---

## How It Works  
- **Server**:  
   - Listens on port `8080` for incoming client connections.  
   - Handles server-side input and forwards messages to the client.  

- **Client**:  
   - Connects to the server on port `8080`.  
   - Sends messages entered by the user to the server.  
   - Displays messages received from the server.  

---

## Branch Information  
This branch is dedicated to the **chat-server** implementation as part of the ongoing **socket-programming** repository. For other examples or extensions, check out the main branch.  

---