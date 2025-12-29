//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define MAX_BOATS 20
#define MAX_NAME_LENGTH 128
#define MAX_LINE_LENGTH 256
#define SLIP_RATE 12.50
#define LAND_RATE 14.00
#define TRAILOR_RATE 25.00
#define STORAGE_RATE 11.20

//------------------------------------------------------------------------------
// Type Definitions
//------------------------------------------------------------------------------
typedef enum {
    SLIP,
    LAND,
    TRAILOR,
    STORAGE
} PlaceType;

typedef union {
    int slipNumber;           // 1-85
    char bayLetter;           // A-Z
    char trailorTag[128];     // License tag
    int storageNumber;        // 1-50
} ExtraInfo;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int length;               // Length in feet
    PlaceType place;
    ExtraInfo info;
    double amountOwed;
} Boat;

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
void loadBoats(const char *filename, Boat **boats, int *count);
void saveBoats(const char *filename, Boat **boats, int count);
int compareBoats(const void *a, const void *b);
void printInventory(Boat **boats, int count);
void addBoat(Boat **boats, int *count, const char *csvLine);
void removeBoat(Boat **boats, int *count, const char *name);
void acceptPayment(Boat **boats, int count, const char *name, double amount);
void updateMonthly(Boat **boats, int count);
void displayMenu();
char getMenuChoice();
int findBoat(Boat **boats, int count, const char *name);
void toLowerCase(char *str);
double getRate(PlaceType place);

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <datafile.csv>\n", argv[0]);
        return 1;
    }

    Boat *boats[MAX_BOATS] = {NULL};
    int boatCount = 0;

    // Load boats from file
    loadBoats(argv[1], boats, &boatCount);

    printf("Welcome to the Boat Management System\n");

    // Main menu loop
    char choice;
    int running = 1;
    while (running) {
        displayMenu();
        choice = getMenuChoice();

        switch (toupper(choice)) {
            case 'I':
                printInventory(boats, boatCount);
                break;
            case 'A': {
                char csvLine[MAX_LINE_LENGTH];
                printf("Please enter the boat data in CSV format                 : ");
                fgets(csvLine, MAX_LINE_LENGTH, stdin);
                csvLine[strcspn(csvLine, "\n")] = 0;  // Remove newline
                addBoat(boats, &boatCount, csvLine);
                break;
            }
            case 'R': {
                char name[MAX_NAME_LENGTH];
                printf("Please enter the boat name                               : ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                removeBoat(boats, &boatCount, name);
                break;
            }
            case 'P': {
                char name[MAX_NAME_LENGTH];
                double amount;
                printf("Please enter the boat name                               : ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                
                int index = findBoat(boats, boatCount, name);
                if (index == -1) {
                    printf("No boat with that name\n");
                } else {
                    printf("Please enter the amount to be paid                       : ");
                    scanf("%lf", &amount);
                    getchar();  // Consume newline
                    acceptPayment(boats, boatCount, name, amount);
                }
                break;
            }
            case 'M':
                updateMonthly(boats, boatCount);
                break;
            case 'X':
                running = 0;
                break;
            default:
                printf("Invalid option %c\n", choice);
                break;
        }
        printf("\n");
    }

    printf("\nExiting the Boat Management System\n");

    // Save boats to file
    saveBoats(argv[1], boats, boatCount);

    // Free all allocated memory
    for (int i = 0; i < boatCount; i++) {
        free(boats[i]);
    }

    return 0;
}

//------------------------------------------------------------------------------
// Function displayMenu
// Displays the main menu options
//------------------------------------------------------------------------------
void displayMenu() {
    printf("\n(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : ");
}

//------------------------------------------------------------------------------
// Function getMenuChoice
// Gets the menu choice from the user
//------------------------------------------------------------------------------
char getMenuChoice() {
    char choice;
    scanf(" %c", &choice);
    getchar();
    return choice;
}

//------------------------------------------------------------------------------
// Function compareBoats
// Comparison function for qsort to sort boats alphabetically by name
//------------------------------------------------------------------------------
int compareBoats(const void *a, const void *b) {
    Boat *boatA = *(Boat **)a;
    Boat *boatB = *(Boat **)b;
    
    char nameA[MAX_NAME_LENGTH], nameB[MAX_NAME_LENGTH];
    strcpy(nameA, boatA->name);
    strcpy(nameB, boatB->name);
    
    toLowerCase(nameA);
    toLowerCase(nameB);
    
    return strcmp(nameA, nameB);
}

//------------------------------------------------------------------------------
// Function toLowerCase
// Converts a string to lowercase for case-insensitive comparison
//------------------------------------------------------------------------------
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

//------------------------------------------------------------------------------
// Function getRate
// Returns the monthly rate per foot based on place type
//------------------------------------------------------------------------------
double getRate(PlaceType place) {
    switch (place) {
        case SLIP: return SLIP_RATE;
        case LAND: return LAND_RATE;
        case TRAILOR: return TRAILOR_RATE;
        case STORAGE: return STORAGE_RATE;
        default: return 0.0;
    }
}

//------------------------------------------------------------------------------
// Function loadBoats
// Loads boat data from CSV file and sorts by name
//------------------------------------------------------------------------------
void loadBoats(const char *filename, Boat **boats, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    *count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) && *count < MAX_BOATS) {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) == 0) continue;

        Boat *newBoat = (Boat *)malloc(sizeof(Boat));
        if (!newBoat) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(1);
        }

        char placeStr[20];
        
        char *token = strtok(line, ",");
        strcpy(newBoat->name, token);
        
        token = strtok(NULL, ",");
        newBoat->length = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(placeStr, token);
        
        // Determine place type
        if (strcmp(placeStr, "slip") == 0) {
            newBoat->place = SLIP;
            token = strtok(NULL, ",");
            newBoat->info.slipNumber = atoi(token);
        } else if (strcmp(placeStr, "land") == 0) {
            newBoat->place = LAND;
            token = strtok(NULL, ",");
            newBoat->info.bayLetter = token[0];
        } else if (strcmp(placeStr, "trailor") == 0) {
            newBoat->place = TRAILOR;
            token = strtok(NULL, ",");
            strcpy(newBoat->info.trailorTag, token);
        } else if (strcmp(placeStr, "storage") == 0) {
            newBoat->place = STORAGE;
            token = strtok(NULL, ",");
            newBoat->info.storageNumber = atoi(token);
        }
        
        token = strtok(NULL, ",");
        newBoat->amountOwed = atof(token);
        
        boats[*count] = newBoat;
        (*count)++;
    }

    fclose(file);
    
    // Sort boats by name
    qsort(boats, *count, sizeof(Boat *), compareBoats);
}

//------------------------------------------------------------------------------
// Function saveBoats
// Saves boat data to CSV file
//------------------------------------------------------------------------------
void saveBoats(const char *filename, Boat **boats, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,", boats[i]->name, boats[i]->length);
        
        switch (boats[i]->place) {
            case SLIP:
                fprintf(file, "slip,%d,", boats[i]->info.slipNumber);
                break;
            case LAND:
                fprintf(file, "land,%c,", boats[i]->info.bayLetter);
                break;
            case TRAILOR:
                fprintf(file, "trailor,%s,", boats[i]->info.trailorTag);
                break;
            case STORAGE:
                fprintf(file, "storage,%d,", boats[i]->info.storageNumber);
                break;
        }
        
        fprintf(file, "%.2f\n", boats[i]->amountOwed);
    }

    fclose(file);
}

//------------------------------------------------------------------------------
// Function printInventory
// Displays all boats in formatted output
//------------------------------------------------------------------------------
void printInventory(Boat **boats, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-20s %3d' ", boats[i]->name, boats[i]->length);
        
        switch (boats[i]->place) {
            case SLIP:
                printf("   slip   # %2d   ", boats[i]->info.slipNumber);
                break;
            case LAND:
                printf("   land      %c   ", boats[i]->info.bayLetter);
                break;
            case TRAILOR:
                printf("trailor %6s   ", boats[i]->info.trailorTag);
                break;
            case STORAGE:
                printf("storage   # %2d   ", boats[i]->info.storageNumber);
                break;
        }
        
        printf("Owes $%7.2f\n", boats[i]->amountOwed);
    }
}

//------------------------------------------------------------------------------
// Function addBoat
// Adds a new boat from CSV format input and maintains sorted order
//------------------------------------------------------------------------------
void addBoat(Boat **boats, int *count, const char *csvLine) {
    if (*count >= MAX_BOATS) {
        printf("Error: Maximum number of boats reached\n");
        return;
    }

    Boat *newBoat = (Boat *)malloc(sizeof(Boat));
    if (!newBoat) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    strcpy(line, csvLine);
    
    char placeStr[20];
    
    char *token = strtok(line, ",");
    strcpy(newBoat->name, token);
    
    token = strtok(NULL, ",");
    newBoat->length = atoi(token);
    
    token = strtok(NULL, ",");
    strcpy(placeStr, token);
    
    // Determine place type
    if (strcmp(placeStr, "slip") == 0) {
        newBoat->place = SLIP;
        token = strtok(NULL, ",");
        newBoat->info.slipNumber = atoi(token);
    } else if (strcmp(placeStr, "land") == 0) {
        newBoat->place = LAND;
        token = strtok(NULL, ",");
        newBoat->info.bayLetter = token[0];
    } else if (strcmp(placeStr, "trailor") == 0) {
        newBoat->place = TRAILOR;
        token = strtok(NULL, ",");
        strcpy(newBoat->info.trailorTag, token);
    } else if (strcmp(placeStr, "storage") == 0) {
        newBoat->place = STORAGE;
        token = strtok(NULL, ",");
        newBoat->info.storageNumber = atoi(token);
    }
    
    token = strtok(NULL, ",");
    newBoat->amountOwed = atof(token);
    
    boats[*count] = newBoat;
    (*count)++;
    
    // Sort boats by name
    qsort(boats, *count, sizeof(Boat *), compareBoats);
}

//------------------------------------------------------------------------------
// Function findBoat
// Searches for a boat by name (case insensitive) and returns its index
//------------------------------------------------------------------------------
int findBoat(Boat **boats, int count, const char *name) {
    char searchName[MAX_NAME_LENGTH];
    strcpy(searchName, name);
    toLowerCase(searchName);
    
    for (int i = 0; i < count; i++) {
        char boatName[MAX_NAME_LENGTH];
        strcpy(boatName, boats[i]->name);
        toLowerCase(boatName);
        
        if (strcmp(boatName, searchName) == 0) {
            return i;
        }
    }
    
    return -1;
}

//------------------------------------------------------------------------------
// Function removeBoat
// Removes a boat by name and maintains array integrity
//------------------------------------------------------------------------------
void removeBoat(Boat **boats, int *count, const char *name) {
    int index = findBoat(boats, *count, name);
    
    if (index == -1) {
        printf("No boat with that name\n");
        return;
    }
    
    free(boats[index]);
    
    // Shift boats down
    for (int i = index; i < *count - 1; i++) {
        boats[i] = boats[i + 1];
    }
    
    (*count)--;
    boats[*count] = NULL;
}

//------------------------------------------------------------------------------
// Function acceptPayment
// Accepts a payment for a boat with validation
//------------------------------------------------------------------------------
void acceptPayment(Boat **boats, int count, const char *name, double amount) {
    int index = findBoat(boats, count, name);
    
    if (index == -1) {
        printf("No boat with that name\n");
        return;
    }
    
    if (amount > boats[index]->amountOwed) {
        printf("That is more than the amount owed, $%.2f\n", boats[index]->amountOwed);
        return;
    }
    
    boats[index]->amountOwed -= amount;
}

//------------------------------------------------------------------------------
// Function updateMonthly
// Calculates and adds monthly charges for all boats
//------------------------------------------------------------------------------
void updateMonthly(Boat **boats, int count) {
    for (int i = 0; i < count; i++) {
        double monthlyCharge = boats[i]->length * getRate(boats[i]->place);
        boats[i]->amountOwed += monthlyCharge;
    }
}

//------------------------------------------------------------------------------
