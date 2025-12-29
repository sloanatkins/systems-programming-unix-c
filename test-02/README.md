## Test 2 – Structs, Enums, and Dynamic Arrays in C

This lab focuses on structured data storage using C structs and enums. The program records information about newly discovered animal species and outputs the collected data in a formatted, readable form.

### Key Topics
- Defining and using C `struct` types
- Enumerated types (`enum`) for categorical data
- Arrays of structures
- User input handling and termination conditions
- Formatted output
- Dynamic memory management using `malloc` and `realloc` (bonus)

---

### Program Implemented

#### New Species Recorder
This program allows a user to enter information about newly discovered animal species.

**Features:**
- Stores up to 10 animal records using an array of structures
- Each record contains:
  - Animal name (up to 128 characters)
  - Size (floating-point value)
  - Animal type represented as an enum (`mammal`, `insect`, `bird`, or `fish`)
- Accepts repeated user input until `"exit"` is entered as the animal name
- Prints a formatted summary of all recorded species
- Converts between string input and enum values using provided helper logic

---

### Bonus Implementation
For additional credit, the program can be extended to:
- Dynamically allocate the array of structures
- Start with an initial size of 1
- Use `realloc` to grow the array as additional animals are entered

This approach demonstrates dynamic memory resizing and flexible data storage.

---

### Files
- C source file implementing the species recording program
- Any supporting headers or helper functions used for enum/string conversion

This lab reinforces fundamental data modeling skills in C and emphasizes clean structure, readability, and disciplined programming style.
