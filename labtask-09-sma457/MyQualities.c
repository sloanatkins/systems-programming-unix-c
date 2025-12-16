//------------------------------------------------------------------------------
// MyQualities.c
// Extracts and sorts qualities from "I am" statements
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUALITIES 20
#define MAX_LINE_LENGTH 256
#define I_AM_PREFIX "I am "
#define I_AM_PREFIX_LENGTH 5
#define TERMINATOR "."
#define OUTPUT_FILENAME "MyQualities.txt"

void ReadQualities(char *qualities[], int *count);
int StartsWithIAm(const char *sentence);
char *ExtractQuality(const char *sentence);
void PrintQualities(char *qualities[], int count);
void SortQualities(char *qualities[], int count);
int CompareQualities(const void *a, const void *b);
void WriteQualitiesToFile(char *qualities[], int count);
void FreeQualities(char *qualities[], int count);

int main(void) {
    char *qualities[MAX_QUALITIES];
    int qualityCount = 0;

    for (int i = 0; i < MAX_QUALITIES; i++) {
        qualities[i] = NULL;
    }

    ReadQualities(qualities, &qualityCount);

    if (qualityCount > 0) {
        printf("\n");
        PrintQualities(qualities, qualityCount);

        SortQualities(qualities, qualityCount);
        printf("\n");
        PrintQualities(qualities, qualityCount);

        WriteQualitiesToFile(qualities, qualityCount);
    } else {
        printf("\nNo qualities were entered.\n");
    }

    FreeQualities(qualities, qualityCount);
    return EXIT_SUCCESS;
}

void ReadQualities(char *qualities[], int *count) {
    char line[MAX_LINE_LENGTH];
    int index = 0;

    printf("Please enter sentences, . to end.\n");

    while (index < MAX_QUALITIES) {
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL)
            break;

        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        if (strcmp(line, TERMINATOR) == 0)
            break;

        if (StartsWithIAm(line)) {
            char *quality = ExtractQuality(line);
            if (quality != NULL)
                qualities[index++] = quality;
        }
    }

    *count = index;
}

int StartsWithIAm(const char *sentence) {
    return (strstr(sentence, I_AM_PREFIX) == sentence);
}

char *ExtractQuality(const char *sentence) {
    size_t qualityLength = strlen(sentence) - I_AM_PREFIX_LENGTH;
    if (qualityLength == 0)
        return NULL;

    char *quality = malloc(qualityLength + 1);
    if (quality == NULL)
        return NULL;

    strncpy(quality, sentence + I_AM_PREFIX_LENGTH, qualityLength);
    quality[qualityLength] = '\0';
    return quality;
}

void PrintQualities(char *qualities[], int count) {
    for (int i = 0; i < count; i++)
        printf("%s\n", qualities[i]);
}

void SortQualities(char *qualities[], int count) {
    qsort(qualities, count, sizeof(char *), CompareQualities);
}

int CompareQualities(const void *a, const void *b) {
    const char *stringA = *(const char **)a;
    const char *stringB = *(const char **)b;
    return strcmp(stringA, stringB);
}

void WriteQualitiesToFile(char *qualities[], int count) {
    FILE *outputFile = fopen(OUTPUT_FILENAME, "w");
    if (outputFile == NULL)
        return;

    for (int i = 0; i < count; i++)
        fprintf(outputFile, "%s\n", qualities[i]);

    fclose(outputFile);
}

void FreeQualities(char *qualities[], int count) {
    for (int i = 0; i < count; i++) {
        if (qualities[i] != NULL)
            free(qualities[i]);
    }
}
//-----------------------------------------------------------------------------
