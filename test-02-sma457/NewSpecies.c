//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define MAX_NAME_LENGTH 128
#define INITIAL_CAPACITY 1
#define EXIT_COMMAND "exit"

//------------------------------------------------------------------------------
// Type Definitions
//------------------------------------------------------------------------------
typedef enum {
    mammal,
    insect,
    bird,
    fish,
    error
} AnimalType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double size;
    AnimalType type;
} Species;

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
AnimalType StringToAnimal(char *AnimalType);
char *AnimalToString(AnimalType TheType);
Species *ReadSpeciesData(int *count);
void DisplaySpecies(Species *species, int count);
void GetUserInput(char *prompt, char *buffer, int maxLength);

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(void) {
    Species *speciesArray = NULL;
    int speciesCount = 0;

    // Read species information from user with dynamic allocation
    speciesArray = ReadSpeciesData(&speciesCount);

    // Display all recorded species
    if (speciesCount > 0) {
        printf("\nThe following new species were found:\n");
        DisplaySpecies(speciesArray, speciesCount);
    } else {
        printf("\nNo species were recorded.\n");
    }

    // Free dynamically allocated memory
    free(speciesArray);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function ReadSpeciesData
// Reads the species information from user input with dynamic memory allocation
//------------------------------------------------------------------------------
Species *ReadSpeciesData(int *count) {
    char nameBuffer[MAX_NAME_LENGTH];
    char sizeBuffer[MAX_NAME_LENGTH];
    char typeBuffer[MAX_NAME_LENGTH];
    Species *species = NULL;
    int index = 0;

    while (1) {
        printf("Enter animal information (\"exit\" to exit)\n");

        // Get species name
        GetUserInput("What is the name : ", nameBuffer, MAX_NAME_LENGTH);

        // Check for exit condition
        if (strcasecmp(nameBuffer, EXIT_COMMAND) == 0) {
            break;
        }

        // Allocate or reallocate memory
        if (index == 0) {
            // First allocation: malloc for size 1
            species = (Species *)malloc(INITIAL_CAPACITY * sizeof(Species));
            if (species == NULL) {
                fprintf(stderr, "Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        } else {
            // Subsequent allocations: realloc to grow the array
            Species *temp = (Species *)realloc(species, (index + 1) * sizeof(Species));
            if (temp == NULL) {
                fprintf(stderr, "Error: Memory reallocation failed.\n");
                free(species);
                exit(EXIT_FAILURE);
            }
            species = temp;
        }

        // Store the name
        strncpy(species[index].name, nameBuffer, MAX_NAME_LENGTH - 1);
        species[index].name[MAX_NAME_LENGTH - 1] = '\0';

        // Get species size
        GetUserInput("What is the size : ", sizeBuffer, MAX_NAME_LENGTH);
        species[index].size = atof(sizeBuffer);

        // Get species type
        GetUserInput("What is the type : ", typeBuffer, MAX_NAME_LENGTH);
        species[index].type = StringToAnimal(typeBuffer);

        // Validate the animal type
        if (species[index].type == error) {
            printf("Warning: Invalid animal type. Using 'error' as type.\n");
        }

        index++;
    }

    *count = index;
    return species;
}

//------------------------------------------------------------------------------
// Function DisplaySpecies
// Displays all recorded species in formatted output
//------------------------------------------------------------------------------
void DisplaySpecies(Species *species, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-20s has size %6.2f and is a %s\n",
               species[i].name,
               species[i].size,
               AnimalToString(species[i].type));
    }
}

//------------------------------------------------------------------------------
// Function GetUserInput
// Displays prompt and read user input, removing trailing newline
//------------------------------------------------------------------------------
void GetUserInput(char *prompt, char *buffer, int maxLength) {
    printf("%s", prompt);
    
    if (fgets(buffer, maxLength, stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

//------------------------------------------------------------------------------
// Function StringToAnimal
// Converts a string to an AnimalType enum value
//------------------------------------------------------------------------------
AnimalType StringToAnimal(char *AnimalType) {
    if (!strcasecmp(AnimalType, "mammal")) {
        return mammal;
    }
    if (!strcasecmp(AnimalType, "insect")) {
        return insect;
    }
    if (!strcasecmp(AnimalType, "bird")) {
        return bird;
    }
    if (!strcasecmp(AnimalType, "fish")) {
        return fish;
    }
    return error;
}

//------------------------------------------------------------------------------
// Function AnimalToString
// Converts an AnimalType enum value to a string
//------------------------------------------------------------------------------
char *AnimalToString(AnimalType TheType) {
    switch (TheType) {
        case mammal:
            return "mammal";
        case insect:
            return "insect";
        case bird:
            return "bird";
        case fish:
            return "fish";
        default:
            return "error";
    }
}

//------------------------------------------------------------------------------

