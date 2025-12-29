## Lab 13 – Client–Server Communication Using Sockets

This lab focuses on basic network programming using sockets in C. The programs demonstrate communication between a client and a server process using TCP sockets, reinforcing fundamental concepts of interprocess communication across a network.

### Key Topics
- Socket-based communication in UNIX
- Client–server architecture
- Establishing and accepting socket connections
- Sending and receiving data using `send` and `recv`
- Handling network I/O without forking
- Using helper libraries for socket setup
- Repeated connection handling in a server loop

---

### Programs Implemented

#### SocketServer
The server program listens for incoming socket connections and processes them sequentially.

**Features:**
- Accepts a port number as a command-line argument
- Creates and listens on a TCP socket
- Repeatedly accepts client connections
- Uses `recv` to read a single line of input from each client
- Closes the socket after receiving data
- Prints the received message to the screen
- Handles connections in a single process without forking

The server runs continuously, processing one connection at a time.

---

#### SocketClient
The client program connects to the server and sends identifying information.

**Features:**
- Accepts a hostname and port number as command-line arguments
- Establishes a socket connection to the server
- Uses `send` to transmit a line containing the client’s machine and domain name
- Closes the socket after sending data

---

### Files
- Server source file implementing socket-based message reception
- Client source file implementing socket-based message sending
- `mysockets.h` / `mysockets.c` – Helper library used for socket setup
- Any output produced during execution

This lab introduces fundamental networking concepts and demonstrates how processes can communicate reliably over a network using sockets.
