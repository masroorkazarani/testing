#include <stdio.h>
#include <string.h>

#define FLAG 'F'
#define ESC 'E'

void characterStuffing(const char *input) {
    printf("Character-Stuffed Frame: %c", FLAG);  // Start of frame

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == FLAG || input[i] == ESC) {
            printf("%c", ESC);  // Add ESC before special characters
        }
        printf("%c", input[i]);
    }
    
    printf("%c\n", FLAG);  // End of frame
}

int main() {
    const char data[] = "ABFCEF";  // Example data
    printf("Original Data: %s\n", data);
    characterStuffing(data);
    return 0;
}