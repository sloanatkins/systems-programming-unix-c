//-----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char sentence[256];
    char qualities[1024] = "";
    char *found;

    printf("Please enter sentences, . to end.\n");

    while (1) {
        // Read a sentence
        fgets(sentence, sizeof(sentence), stdin);

        // Remove newline if it exists
        sentence[strcspn(sentence, "\n")] = '\0';

        // Stop if user enters "."
        if (strcmp(sentence, ".") == 0)
            break;

        // Check if the sentence starts with "I am "
        if ((found = strstr(sentence, "I am ")) == sentence) {
            char quality[256];
            strncpy(quality, sentence + 5, sizeof(quality) - 1);
            quality[sizeof(quality) - 1] = '\0';

            // Add comma separator if not the first one
            if (strlen(qualities) > 0)
                strncat(qualities, ", ", sizeof(qualities) - strlen(qualities) - 1);

            // Add this new quality to the big string
            strncat(qualities, quality, sizeof(qualities) - strlen(qualities) - 1);
        }
    }

    printf("The qualities are %s.\n", qualities);
    return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------
