#include <stdio.h>
#include <string.h>

void bitStuffing(const char *input) {
    int count = 0;
    printf("Bit-Stuffed Frame: ");
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            count++;
            printf("1");
            if (count == 5) {  // After five 1s, stuff a 0
                printf("0");
                count = 0;  // Reset counter
            }
        } else {
            printf("0");
            count = 0;  // Reset counter for any 0
        }
    }
    printf("\n");
}

int main() {
    const char data[] = "11111011111101111110";  // Example bit stream
    printf("Original Data: %s\n", data);
    bitStuffing(data);
    return 0;
}