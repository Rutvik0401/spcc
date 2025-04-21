#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Stack for Shift-Reduce Parsing
char stack[MAX];
int top = -1;

// Function to push elements to the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop elements from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Function to perform Shift-Reduce Parsing
void shiftReduceParser(char input[]) {
    int i = 0;
    int length = strlen(input);
    
    // Start parsing
    printf("Input: %s\n", input);
    while (i < length) {
        printf("Stack: ");
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }
        printf(", Input: ");
        for (int j = i; j < length; j++) {
            printf("%c", input[j]);
        }
        printf("\n");

        // Perform Shift operation
        push(input[i]);
        i++;

        // Perform Reduce if possible
        // Check for the pattern "aSb" and reduce it to "S"
        if (top >= 2 && stack[top] == 'b' && stack[top - 1] == 'S' && stack[top - 2] == 'a') {
            // Reduce aSb → S
            pop(); // Remove 'b'
            pop(); // Remove 'S'
            pop(); // Remove 'a'
            push('S'); // Push 'S'
            printf("Reduced to S\n");
        }
    }

    // Final Output
    printf("Stack: ");
    for (int j = 0; j <= top; j++) {
        printf("%c", stack[j]);
    }
    printf("\n");
    
    if (top == 0 && stack[top] == 'S') {
        printf("Input string is accepted (parsed successfully).\n");
    } else {
        printf("Input string is rejected.\n");
    }
}

int main() {
    char input[MAX];

    printf("Enter a string to parse (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    // Call the Shift-Reduce parser
    shiftReduceParser(input);

    return 0;
}
