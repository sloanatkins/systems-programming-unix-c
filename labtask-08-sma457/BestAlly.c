#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------------------------------------
typedef struct Country {
    char name[50];
    struct Country* bestAlly;
    struct Country* next;
} Country;

//-----------------------------------------------------------------------------
Country* createNode(char* name) {
    Country* node = (Country*) malloc(sizeof(Country));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(node->name, name);
    node->bestAlly = NULL;
    node->next = NULL;
    return node;
}

//-----------------------------------------------------------------------------
Country* findCountry(Country* head, char* name) {
    Country* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//-----------------------------------------------------------------------------
int main() {

    Country* head = NULL;
    Country* tail = NULL;
    char input[50];

    // Enter the names of the countries
    while (1) {
        printf("Enter nation name : ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            break;

        Country* newNode = createNode(input);
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }

    // Enter best allies
    Country* current = head;
    while (current != NULL) {
        char ally[50];
        printf("Enter best ally name for %-8s: ", current->name);
        fgets(ally, sizeof(ally), stdin);
        ally[strcspn(ally, "\n")] = '\0';
        current->bestAlly = findCountry(head, ally);
        current = current->next;
    }

    // Print results
    current = head;
    while (current != NULL) {
        printf("The best ally of %-8s is %s\n", current->name, current->bestAlly->name);
        current = current->next;
    }

    // Free memory
    while (head != NULL) {
        Country* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
