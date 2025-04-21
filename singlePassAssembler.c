#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct symbol {
    char label[20];
    int address;
};

struct opcode {
    char code[10];
    int value;
};

int main() {
    FILE *fp;
    char line[50], label[20], op[20], arg[20];
    int loc = 0, symCount = 0, i;
    struct symbol symtab[20];

    // Simple opcode table
    struct opcode mot[] = {
        {"START", -1}, {"MOVER", 1}, {"ADD", 2}, {"MOVEM", 3}, {"STOP", 4},
        {"DC", -1}, {"DS", -1}, {"END", -1}
    };
    int motSize = sizeof(mot)/sizeof(mot[0]);

    fp = fopen("input.asm", "r");

    printf("Intermediate Code:\n");
    printf("LOC\tOPCODE\tARG\n");

    while (fgets(line, sizeof(line), fp)) {
        int tokens = sscanf(line, "%s %s %s", label, op, arg);

        // Handle START
        if (strcmp(op, "START") == 0) {
            loc = atoi(arg);
            printf("%d\t%s\t%s\n", loc, op, arg);
            continue;
        }

        // Label present
        if (tokens == 3) {
            strcpy(symtab[symCount].label, label);
            symtab[symCount].address = loc;
            symCount++;
        }

        // Print intermediate code
        if (strcmp(op, "DC") == 0 || strcmp(op, "DS") == 0) {
            printf("%d\t%s\t%s\n", loc, op, arg);
        } else if (strcmp(op, "END") == 0) {
            printf("%d\t%s\n", loc, op);
        } else {
            printf("%d\t%s\t%s\n", loc, op, arg);
        }

        loc++;
    }

    fclose(fp);

    // Print Symbol Table
    printf("\nSymbol Table:\n");
    for (i = 0; i < symCount; i++) {
        printf("%s\t%d\n", symtab[i].label, symtab[i].address);
    }

    return 0;
}

//Put this inside input.asm:
// START 100
// LOOP   MOVER AREG, DATA
//        ADD AREG, VALUE
//        MOVEM AREG, RESULT
//        STOP
// DATA   DC 5
// VALUE  DC 10
// RESULT DS 1
// END
// gcc single_pass_assembler.c -o assembler
// ./assembler