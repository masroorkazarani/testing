#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter number of frames to send: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nSending frame %d...", i);

        if (rand() % 2)
        { // Randomly simulate ACK loss
            printf(" ACK lost. Resending...");
            i--; // Resend the same frame
        }
        else
        {
            printf(" ACK received for frame %d.", i);
        }
    }

    printf("\nAll frames sent successfully!\n");
    return 0;
}
