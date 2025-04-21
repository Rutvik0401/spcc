#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char keywords[][10] = {"int", "float", "if", "else", "while", "return"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char line[100];
    char token[20];
    int i = 0, j = 0;

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    while (line[i] != '\0') {
        if (isalnum(line[i])) {
            token[j++] = line[i];
        } else {
            if (j != 0) {
                token[j] = '\0';
                j = 0;
                if (isKeyword(token))
                    printf("'%s' is a Keyword\n", token);
                else if (isdigit(token[0]))
                    printf("'%s' is a Constant\n", token);
                else
                    printf("'%s' is an Identifier\n", token);
            }

            if (line[i] == '+' || line[i] == '-' || line[i] == '=' || line[i] == ';')
                printf("'%c' is an Operator or Symbol\n", line[i]);
        }
        i++;
    }

    return 0;
}
