## Boat Management System – Marina Inventory and Billing

This project implements an interactive marina management system in C that tracks boats stored at a marina, calculates monthly charges, processes payments, and persists data using a CSV file. The program emphasizes structured data modeling, dynamic memory management, and robust user interaction.

---

### Overview

The Boat Management System maintains records for up to 20 boats stored at a marina. Each boat has associated metadata (name, length, storage type, location details, and balance owed), and charges are computed monthly based on storage type.

All boat records are:
- Stored dynamically using `malloc`
- Referenced via an array of pointers
- Kept sorted alphabetically by boat name using `qsort`
- Loaded from and saved back to a CSV file

---

### Data Model

Each boat is represented by a dynamically allocated structure containing:
- Boat name (string, up to 128 characters)
- Boat length in feet
- Storage type (`slip`, `land`, `trailor`, or `storage`) implemented using an `enum`
- Location-specific data implemented using a `union`:
  - Slip number (1–85)
  - Land bay letter (A–Z)
  - Trailor license tag
  - Storage space number (1–50)
- Amount owed to the marina

---

### Storage Rates

| Location Type | Monthly Rate |
|--------------|--------------|
| Slip         | $12.50 / foot |
| Land         | $14.00 / foot |
| Trailor      | $25.00 / foot |
| Storage      | $11.20 / foot |

---

### Program Features

Upon startup, the program loads boat data from a CSV file specified as a command-line argument. While running, the user is presented with a menu-driven interface that supports:

- **Inventory**  
  Display all boats sorted alphabetically by name

- **Add**  
  Add a boat using a CSV-formatted input string

- **Remove**  
  Remove a boat by name (case-insensitive)

- **Payment**  
  Apply a payment toward a boat’s outstanding balance

- **Month**  
  Advance the system by one month and apply new storage charges

- **Exit**  
  Save all data back to the CSV file and cleanly free allocated memory

Menu options are case-insensitive, and invalid input is handled gracefully.

---

### File Persistence

Boat records are stored in a comma-separated values file with the format:

