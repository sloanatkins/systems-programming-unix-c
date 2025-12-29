## Lab 09 – Dynamic Strings, Sorting, and File Output in C

This lab focuses on managing dynamically allocated strings using arrays of pointers, sorting data using the C standard library, and writing structured output to a file. Emphasis is placed on safe string handling, memory allocation, and disciplined program flow.

### Key Topics
- Arrays of pointers to dynamically allocated memory
- Safe string input using `fgets`
- Substring detection and extraction
- Dynamic memory allocation with `malloc`
- String copying using bounded functions
- Sorting strings alphabetically using `qsort`
- File output using standard I/O functions
- Proper memory management and cleanup

---

### Program Implemented

#### Self-Described Qualities Collector
This program analyzes user-entered sentences to extract and process self-described qualities.

**Features:**
- Reads sentences from standard input until a termination condition is met
- Detects sentences beginning with `"I am "`
- Extracts and stores the descriptive substring dynamically
- Maintains up to 20 dynamically allocated quality strings
- Prints the extracted qualities in original order
- Sorts the qualities alphabetically using `qsort`
- Outputs the sorted list to both the screen and a text file
- Writes results to `MyQualities.txt` in a clean, line-by-line format

The program demonstrates careful use of pointers, dynamic allocation, and standard library utilities for sorting and file I/O.

---

### Files
- C source file implementing the qualities extraction and sorting program
- `MyQualities.txt` – Output file containing sorted qualities

This lab reinforces key systems programming concepts, including memory management, pointer manipulation, and use of library-provided algorithms.
