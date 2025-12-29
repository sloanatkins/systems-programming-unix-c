## Lab 11 – Signal Handling and Interprocess Communication in UNIX

This lab focuses on UNIX signal handling, interprocess communication, and process lifecycle management. The programs demonstrate coordinated behavior between a sender and receiver process using asynchronous signals.

### Key Topics
- Signal handling using `signal` / `sigaction`
- Asynchronous event-driven programming
- Alarm timers and signal scheduling
- Interprocess communication via signals
- Process creation using `fork`
- Process synchronization with `pause`
- Graceful termination and zombie cleanup
- Ignoring and handling specific UNIX signals

---

### Programs Implemented

#### SignalSender
The sender program manages alarms and user interrupts while communicating with a child receiver process.

**Features:**
- Installs a handler for `SIGINT` that:
  - Prints a message
  - Resets a 5-second alarm
  - Sends a `SIGUSR1` signal to the receiver
- Installs a handler for `SIGALRM` that:
  - Increments and reports the number of alarms handled
  - Resets the alarm for 5 seconds later
- Forks a child process to execute the receiver program
- Uses a loop with `pause()` to wait for signals
- Terminates after handling three alarm signals
- Disables alarms, sends `SIGKILL` to the receiver, and cleans up the child process

The sender program demonstrates controlled termination using signals while allowing user-generated interrupts to defer alarms.

---

#### SignalReceiver
The receiver program responds to signals sent by the sender.

**Features:**
- Ignores `SIGINT` signals
- Installs a handler for `SIGUSR1` that prints a message
- Runs indefinitely using `pause()` to wait for signals

The receiver program illustrates simple signal-based interprocess communication.

---

### Files
- Sender program source file
- Receiver program source file
- Any output generated during execution

This lab reinforces core UNIX concepts including signal-driven execution, parent-child process coordination, and robust cleanup of system resources.
