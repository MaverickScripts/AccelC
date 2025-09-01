#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[256];
    FILE *out = fopen("output.c", "w");
    if (!out) {
        printf("Error creating output.c\n");
        return 1;
    }

    fprintf(out, "#include <stdio.h>\n\nint main() {\n");

    printf("WELCOME TO AccelC\n");
    printf("Enter toy language code (end with END):\n");

    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;

        line[strcspn(line, "\n")] = 0;  

        if (strcmp(line, "END") == 0) break;

        if (strncmp(line, "PRINT", 5) == 0) {
            char *text = line + 6;
            fprintf(out, "    printf(\"%s\\n\");\n", text);
        }

        else if (strncmp(line, "SET", 3) == 0) {
            char var[50];
            int value;
            if (sscanf(line, "SET %s %d", var, &value) == 2) {
                fprintf(out, "    int %s = %d;\n", var, value);
            }
        }

        else if (strncmp(line, "ADD", 3) == 0) {
            char a[50], b[50];
            if (sscanf(line, "ADD %s %s", a, b) == 2) {
                fprintf(out, "    printf(\"%%d\\n\", (%s + %s));\n", a, b);
            }
        }
        else if (strncmp(line, "MUL", 3) == 0) {
            char a[50], b[50];
            if (sscanf(line, "MUL %s %s", a, b) == 2) {
                fprintf(out, "    printf(\"%%d\\n\", (%s * %s));\n", a, b);
            }
        }

        
        else if (strncmp(line, "IF", 2) == 0) {
            char left[50], right[50], op[3], text[200];

            int num;
            if (sscanf(line, "IF %s %2s %d PRINT %[^\n]", left, op, &num, text) == 4) {
                if (strcmp(op, ">") == 0)
                    fprintf(out, "    if (%s > %d) printf(\"%s\\n\");\n", left, num, text);
                else if (strcmp(op, "<") == 0)
                    fprintf(out, "    if (%s < %d) printf(\"%s\\n\");\n", left, num, text);
                else if (strcmp(op, "==") == 0)
                    fprintf(out, "    if (%s == %d) printf(\"%s\\n\");\n", left, num, text);
            }
            
            else if (sscanf(line, "IF %[^><=] %2[><=] %s PRINT %[^\n]", left, op, right, text) == 4) {
                if (strcmp(op, ">") == 0)
                    fprintf(out, "    if (%s > %s) printf(\"%s\\n\");\n", left, right, text);
                else if (strcmp(op, "<") == 0)
                    fprintf(out, "    if (%s < %s) printf(\"%s\\n\");\n", left, right, text);
                else if (strcmp(op, "==") == 0)
                    fprintf(out, "    if (%s == %s) printf(\"%s\\n\");\n", left, right, text);
            }
        }

        else {
            printf("Unknown command!\n");
        }
    }

    fprintf(out, "    return 0;\n}\n");
    fclose(out);

    printf("\nCompilation stage...\n");
#ifdef _WIN32
    system("gcc output.c -o output.exe");
    printf("Running program:\n");
    system("output.exe");
#else
    system("gcc output.c -o output");
    printf("Running program:\n");
    system("./output");
#endif

    return 0;
}
