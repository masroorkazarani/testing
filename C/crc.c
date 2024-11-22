#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xor_operation(char *dividend, char *divisor, int length)
{
    for (int i = 0; i < length; i++)
    {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

// CRC calculation function
void calculate_crc(char *data, char *polynomial)
{
    int data_len = strlen(data);
    int poly_len = strlen(polynomial);

    // Append zeros to data
    for (int i = data_len; i < data_len + poly_len - 1; i++)
    {
        data[i] = '0';
    }
    data[data_len + poly_len - 1] = '\0';

    // CRC division process
    for (int i = 0; i < data_len; i++)
    {
        if (data[i] == '1')
        {
            xor_operation(data + i, polynomial, poly_len);
        }
    }
}

int main()
{
    char data[100], polynomial[20];
    int choice;
    int on=1;
    while (on==1)
    {
        printf("\nCRC Polynomial Selection:\n");
        printf("1. CRC-12\n2. CRC-16\n3. CRC-CCITT\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        // Select polynomial based on choice
        switch (choice)
        {
        case 1:
            strcpy(polynomial, "1100000001111");
            break;
        case 2:
            strcpy(polynomial, "11000000000000101");
            break;
        case 3:
            strcpy(polynomial, "10001000000100001");
            break;
        default:
            continue;
        }

        printf("Enter data: ");
        scanf("%s", data);

        calculate_crc(data, polynomial);

        printf("Remainder (CRC): %s\n", data + strlen(data) - (strlen(polynomial) - 1));
        on++;
    }

    return 0;
}
