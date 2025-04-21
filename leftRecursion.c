#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char nonTerm, char grammar[10][50], int n) {
    char newNonTerm = nonTerm + 1;  // New non-terminal to replace the left-recursive one
    printf("Eliminating Left Recursion for non-terminal %c:\n", nonTerm);

    // Print the new grammar with left recursion removed
    printf("New grammar:\n");
    for (int i = 0; i < n; i++) {
        if (grammar[i][0] == nonTerm) {
            // Left recursive rule: A → Aα | β
            printf("%c → ", nonTerm);
            int j = 2;
            while (grammar[i][j] != '\0' && grammar[i][j] != '|') {
                printf("%c", grammar[i][j]);
                j++;
            }
            printf("%c%c\n", newNonTerm, '\'');
            
            printf("%c' → ", newNonTerm);
            j++;
            while (grammar[i][j] != '\0') {
                printf("%c", grammar[i][j]);
                j++;
            }
            printf("| ε\n");
        }
    }
    printf("\n");
}

int main() {
    char grammar[10][50];
    int n;
    char nonTerm;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    // Get the grammar from the user
    printf("Enter the grammar (e.g., A → Aα | β):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", grammar[i]);
    }

    printf("Enter the non-terminal for left recursion elimination (e.g., A): ");
    scanf(" %c", &nonTerm);

    // Call the function to eliminate left recursion
    eliminateLeftRecursion(nonTerm, grammar, n);

    return 0;
}
