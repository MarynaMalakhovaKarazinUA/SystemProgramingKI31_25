#include <stdio.h>

int main() {
    const char* filename = "test.txt"; 

    FILE* file = fopen(filename, "r"); 
    if (file) {
        printf("The file '%s' exists.\n", filename);
        fclose(file);
    }
    else {
        printf("The file '%s' does not exist.\n", filename);
    }

    return 0;
}
