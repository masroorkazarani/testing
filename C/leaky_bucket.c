#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUCKET_SIZE 512

void processPacket(int packetSize, int outputRate)
{
    if (packetSize > BUCKET_SIZE)
    {
        printf("\nBucket overflow. Packet size (%d bytes) too large!", packetSize);
    }
    else
    {
        while (packetSize > 0)
        {
            if (packetSize > outputRate)
            {
                printf("\n\t%d bytes outputted.", outputRate);
                packetSize -= outputRate;
                sleep(1);
            }
            else
            {
                printf("\n\tLast %d bytes sent.", packetSize);
                packetSize = 0;
            }
        }
        printf("\nBucket output successful.");
    }
}

int main()
{
    int outputRate, packetSize;

    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    for (int i = 1; i <= 5; i++)
    {
        sleep(rand() % 5 + 1); // Simulate random delay
        packetSize = rand() % 1000 + 1;

        printf("\nPacket %d: Packet size = %d bytes", i, packetSize);
        processPacket(packetSize, outputRate);
    }

    return 0;
}
