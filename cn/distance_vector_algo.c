#include <stdio.h>
#define MAX 10
#define INF 999

void distanceVector(int n, int cost[MAX][MAX])
{
    int dist[MAX][MAX];
    int next[MAX][MAX]; // Added to track next hop
    int i, j, k, count = 0;

    // Initialize distance and next hop matrices
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = cost[i][j];
            if (i == j)
                next[i][j] = i;
            else if (cost[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Core distance vector algorithm
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k]; // Update next hop
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    // Print the routing table with correct next hop information
    for (i = 0; i < n; i++)
    {
        printf("\nRouting Table for Node %d:\n", i);
        printf("Dest\tNext Hop\tDist\n");
        printf("------------------------\n");
        for (j = 0; j < n; j++)
        {
            printf("%d\t", j);
            if (next[i][j] == -1)
                printf("---\t\t");
            else
                printf("%d\t\t", next[i][j]);

            if (dist[i][j] == INF)
                printf("INF\n");
            else
                printf("%d\n", dist[i][j]);
        }
    }
}

int main()
{
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = INF;
            }
        }
    }

    distanceVector(n, cost);
    return 0;
}
