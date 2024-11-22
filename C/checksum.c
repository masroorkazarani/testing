#include <stdio.h>
#include <string.h>

int main()
{
    char a[20], b[20], sum[20];
    int carry = 0, length;

    printf("Enter first binary string: ");
    scanf("%s", a);
    printf("Enter second binary string: ");
    scanf("%s", b);

    if (strlen(a) != strlen(b))
    {
        printf("\nError: Strings must be of the same length.\n");
        return 1;
    }

    length = strlen(a);

    // Binary addition and 1's complement in one go
    for (int i = length - 1; i >= 0; i--)
    {
        int bit_sum = (a[i] - '0') + (b[i] - '0') + carry;
        sum[i] = (bit_sum % 2) ? '0' : '1'; 
        carry = bit_sum / 2;
    }

    sum[length] = '\0';

    printf("\nChecksum: %s\n", sum);
    return 0;
}
