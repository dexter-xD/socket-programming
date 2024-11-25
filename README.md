# **Socket Programming in C**  

This repository demonstrates the basics of **socket programming** in C through a simple client-server communication example. The server listens for client connections, receives a message, and responds. The client connects to the server, sends a message, and displays the response.

---

## **Features**  
- 📡 **Server Program**: Accepts connections and responds to client messages.  
- 🤝 **Client Program**: Connects to the server and sends messages.  
- 🛠️ Step-by-step implementation with clear code structure.  

---

## **Getting Started**  

### **Prerequisites**  
Make sure you have the following installed:  
- GCC (GNU Compiler Collection)  
- A Linux environment (e.g., Ubuntu, WSL, or a compatible system)  

---

### **How to Run**  

#### **1. Clone the Repository**  
```bash
git clone https://github.com/dexter-xD/socket-programming
cd socket-programming-c
```

#### **2. Compile the Code**  
- **Server Program**  
  ```bash
  gcc server.c -o server
  ```
- **Client Program**  
  ```bash
  gcc client.c -o client
  ```

#### **3. Run the Programs**  
- Start the **Server** in one terminal:  
  ```bash
  ./server
  ```
- Start the **Client** in another terminal:  
  ```bash
  ./client
  ```

---

## **Output**  
- **Server Output**:  
  ```
  Hello from client
  Hello message sent
  ```

- **Client Output**:  
  ```
  Hello message sent
  Hello from server
  ```

---

## **Code Overview**  

### **Server (server.c)**  
The server:  
- Creates a listening socket.  
- Accepts a connection from the client.  
- Reads a message from the client and sends a response.

### **Client (client.c)**  
The client:  
- Creates a socket.  
- Connects to the server.  
- Sends a message to the server and reads the response.

---

## **Learn More**  
For a detailed explanation, check out the accompanying blog post:  
👉 [Blog Post Link](https://evolveasdev.com/blogs/guide/beginners-guide-to-socket-programming-in-c-step-by-step-explanation)  

---

### **Contribute**  
Found an issue or have ideas for improvement? Contributions are welcome! Feel free to open an issue or submit a pull request.  

---

Happy Coding! 🚀
