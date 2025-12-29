## Threaded Fibonacci Server with CPU Limits and IPC

This project implements a multi-threaded Fibonacci computation server that communicates with a user interface process via a named pipe. The system demonstrates advanced UNIX systems programming concepts including interprocess communication, signal handling, CPU usage limits, and concurrent computation using detached threads.

---

### Overview

The system consists of two cooperating programs:

- **ThreadFibServer** – A server that manages Fibonacci computations under a CPU usage limit
- **Interface program** – A user-facing process that sends computation requests to the server

The two programs communicate using a named pipe and signals. The server spawns detached threads to compute Fibonacci numbers concurrently using an intentionally expensive recursive algorithm.

---

### Server Responsibilities

The Fibonacci server performs the following tasks:

- Creates (or reuses) a named pipe called `FIBOPIPE`
- Limits its CPU usage based on a command-line argument
- Installs a `SIGXCPU` handler that:
  - Ignores subsequent `SIGXCPU` signals
  - Sends `SIGUSR1` to the interface process
  - Ensures interrupted reads are **not restarted**
- Forks a child process to run the interface program
- Opens the named pipe for reading
- Repeatedly:
  - Reports CPU time used (excluding interface time)
  - Reads an integer `N` from the pipe
  - Spawns and detaches a new thread to compute Fibonacci(N)
- Tracks the number of running threads using a global counter
- On receiving `0`:
  - Stops accepting work
  - Waits for all threads to complete
  - Reports final CPU usage
  - Cleans up the interface zombie
  - Deletes the named pipe
  - Exits cleanly

Each worker thread:
- Computes the Nth Fibonacci number using a recursive O(2ⁿ) algorithm
- Prints the result
- Decrements the global running-thread counter

---

### Interface Responsibilities

The interface program provides user interaction and forwards requests to the server:

- Installs a `SIGUSR1` handler that:
  - Stops the input loop
  - Ensures a terminating `0` is sent to the server
  - Prevents interrupted reads from restarting
- Opens the named pipe for writing
- Repeatedly:
  - Prompts the user for a positive integer
  - Writes the value to the pipe
- Terminates cleanly when instructed by the server or when input ends

---

### Communication Mechanisms

- **Named pipe (`FIBOPIPE`)** for sending integers from interface to server
- **Signals**
  - `SIGXCPU` to enforce CPU usage limits
  - `SIGUSR1` to signal interface termination
- **Detached POSIX threads** for concurrent Fibonacci computation

---

### Key Concepts Demonstrated

- Named pipes (FIFOs)
- Interprocess communication (IPC)
- POSIX threads and detached thread lifecycle
- Signal handling and interruption semantics
- CPU usage limits and monitoring
- Forking and process cleanup
- Shared global state with concurrent access
- Graceful shutdown under resource constraints

---

### Files

- Server source file (ThreadFibServer)
- Interface source file
- Any supporting headers or utilities
- Named pipe `FIBOPIPE` (created and removed at runtime)

---

### Notes

The Fibonacci algorithm is intentionally inefficient to stress CPU usage and demonstrate concurrency, signal handling, and system-enforced limits. The project emphasizes correctness, robustness, and clean process termination rather than algorithmic efficiency.

This project represents one of the most advanced systems programming exercises in the course.
