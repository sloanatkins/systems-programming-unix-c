## Lab 12 – Multithreading and Shared State in C

This lab focuses on multithreaded programming using POSIX threads. The program demonstrates communication between concurrently running threads via a shared global variable, emphasizing coordination, synchronization by convention, and process lifetime management.

### Key Topics
- POSIX threads (`pthread`)
- Detached thread creation
- Concurrent execution and CPU yielding
- Shared global state between threads
- Producer–consumer style communication
- Process termination triggered from a worker thread
- Input handling and end-of-file detection

---

### Program Implemented

#### Thread-Based Producer–Consumer Buffer
This program starts two detached threads that communicate through a shared global string buffer.

**Main Thread Responsibilities:**
- Initializes the shared global string to empty
- Creates the producer and consumer threads
- Detaches both threads
- Exits immediately, leaving the threads running

**Producer Thread:**
- Waits until the shared string buffer is empty
- Prompts the user for input
- Reads a string from standard input into the shared buffer
- Continues until end-of-file (`^D`) is encountered
- Terminates the entire process when input ends

**Consumer Thread:**
- Waits until the shared string buffer is non-empty
- Prints the contents of the buffer
- Resets the buffer to empty
- Runs indefinitely until the process exits

This design illustrates thread interaction through shared memory and demonstrates how threads can continue executing after the main thread exits.

---

### Files
- C source file implementing the multithreaded producer and consumer
- Any output generated during execution

This lab highlights essential concepts in concurrent programming, including thread lifecycle management and safe coordination through shared state.
