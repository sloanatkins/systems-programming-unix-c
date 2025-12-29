## Lab 08 – Linked Lists and Dynamic Memory Management in C

This lab focuses on building and managing a dynamically allocated linked data structure in C. The program models relationships between entities using pointers, reinforcing correct use of `malloc`, pointer traversal, and explicit memory cleanup.

### Key Topics
- Dynamic memory allocation using `malloc` and `free`
- Singly linked list construction and traversal
- Pointer relationships between data structures
- Storing and referencing related nodes within a list
- Safe input handling and termination conditions
- Explicit memory management and cleanup

---

### Program Implemented

#### Best Ally Tracker
This program allows a user to record a set of countries and identify each country’s perceived best ally.

**Features:**
- Accepts a list of country names until a blank line is entered
- Stores each country in a dynamically allocated linked list node
- Prompts for and records each country’s best ally
- Represents ally relationships using pointers between list nodes
- Outputs the best ally for each country
- Explicitly frees all allocated memory before program termination

Each linked list node contains:
- The country name
- A pointer to the node representing its best ally
- A pointer to the next node in the list

This design ensures efficient traversal and accurate representation of relationships without duplicating data.

---

### Files
- C source file implementing the linked list and ally relationships
- Any supporting files generated during compilation or testing

This lab emphasizes disciplined pointer usage and memory management, both of which are essential skills for low-level and systems programming.

