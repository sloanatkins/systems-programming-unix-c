## Lab 07 – Bit Manipulation and String Processing in C

This lab focuses on low-level bit manipulation using macros and practical string processing using standard C library functions. The exercises emphasize precision, correctness, and safe handling of data at both the bit and character level.

### Key Topics
- Bitwise operations and binary representation of integers
- Macros for examining and testing individual bits
- Bit masking and range-based bit checks
- Safe string input using `fgets`
- String searching, copying, and concatenation
- Managing fixed-size buffers safely
- Loop control and termination conditions

---

### Programs Implemented

#### BitOps.c – Bitwise Macros and Integer Analysis
This program extends an existing bit manipulation utility by adding macros to analyze specific bits within an unsigned integer.

**Features:**
- Determines whether an integer is odd or even using bitwise operations
- Checks whether the Nth least significant bit is set
- Determines whether all bits within a specified range are set
- Uses macros to encapsulate bit-testing logic
- Produces clear textual output describing bit states

This program reinforces understanding of binary representation and efficient low-level checks using bitwise operators.

---

#### IAm.c – String Parsing and Aggregation
This program analyzes user-entered sentences to extract self-described qualities.

**Features:**
- Reads input safely using `fgets`
- Detects sentences beginning with `"I am "` using substring search
- Extracts and accumulates descriptive phrases
- Concatenates results into a bounded buffer using safe string functions
- Terminates input processing on a sentinel value
- Outputs a comma-separated list of extracted qualities

This program emphasizes careful string handling and defensive programming practices in C.

---

### Files
- `BitOps.c` – Bit manipulation program with custom macros
- `IAm.c` – String processing program for extracting and aggregating phrases
- Any compiled binaries or test outputs generated during execution

This lab highlights essential systems programming skills involving bit-level reasoning and robust string manipulation in C.
