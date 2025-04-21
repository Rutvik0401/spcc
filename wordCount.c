#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, count = 0, inWord = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);  // takes input with spaces

    for(i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;  // space means we’re not in a word
        } else if (inWord == 0) {
            inWord = 1;  // start of a new word
            count++;
        }
    }

    printf("Number of words: %d\n", count);

    return 0;
}
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX_WORDS 50
// #define MAX_LEN 20

// int main() {
//     char str[200], words[MAX_WORDS][MAX_LEN];
//     int i = 0, j, k, wordCount = 0, found;
//     int freq[MAX_WORDS] = {0};

//     printf("Enter a sentence: ");
//     fgets(str, sizeof(str), stdin);

//     // Split words
//     char *token = strtok(str, " \n\t");

//     while (token != NULL) {
//         // Convert to lowercase (optional)
//         for (j = 0; token[j]; j++) {
//             token[j] = tolower(token[j]);
//         }

//         // Check if the word is already in the list
//         found = 0;
//         for (j = 0; j < wordCount; j++) {
//             if (strcmp(words[j], token) == 0) {
//                 freq[j]++;
//                 found = 1;
//                 break;
//             }
//         }

//         // If not found, add to the list
//         if (!found) {
//             strcpy(words[wordCount], token);
//             freq[wordCount] = 1;
//             wordCount++;
//         }

//         token = strtok(NULL, " \n\t");
//     }

//     // Print results
//     printf("\nWord Frequency:\n");
//     for (i = 0; i < wordCount; i++) {
//         printf("%s: %d\n", words[i], freq[i]);
//     }

//     return 0;
// }
