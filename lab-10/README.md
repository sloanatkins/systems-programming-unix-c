## Lab 10 – Process Creation and Batch Execution in UNIX

This lab focuses on executing external programs from within a C program using UNIX process control. The program reads a list of commands from a file, launches each command as a background process, and synchronizes execution by waiting for all processes to complete before exiting.

### Key Topics
- Reading command files from disk
- Parsing command-line arguments
- Tokenizing input into program names and parameters
- Creating processes using `fork`
- Executing external programs with `exec`
- Running multiple processes concurrently in the background
- Process synchronization using `wait` / `waitpid`
- Managing program termination and cleanup

---

### Program Implemented

#### Batch Process Starter
This program accepts a filename as a command-line argument. The file contains a list of commands, one per line, including optional parameters.

**Features:**
- Reads commands line-by-line from a specified input file
- Parses each line into a program name and argument list
- Launches each command as a background process
- Allows multiple programs to execute concurrently
- Waits for all child processes to complete before terminating
- Ensures correct parent/child process behavior

Example command file contents:
