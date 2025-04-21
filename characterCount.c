#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int freq[256] = {0}; // ASCII size
    int i, total = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    // Count frequencies
    for(i = 0; word[i] != '\0'; i++) {
        freq[(int)word[i]]++;
        total++;
    }

    // Output total characters
    printf("\nTotal number of characters: %d\n", total);

    // Output frequency of each character
    printf("Character frequencies:\n");
    for(i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            printf("%c : %d\n", i, freq[i]);
        }
    }

    return 0;
}
