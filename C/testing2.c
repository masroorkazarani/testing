#include <stdio.h>
#define MAX 20
void BroadcastTree(int alg[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int parent[MAX];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    visited[start] = 1;
    for (int count = 0; count < n - 1; count++)
    {
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (alg[i][j] && !visited[j])
                    {
                        visited[j] = 1;
                        parent[j] = i;
                    }
                }
            }
        }
    }
    printf("broadcast Tree start from %d\n", start);
    printf("node\tparent\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i, parent[i]);
    }
}
int main()
{
    int n, start;
    int alg[MAX][MAX];
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &alg[i][j]);
        }
        printf("Enter the start\n");
        scanf("%d", &start);
        BroadcastTree(alg, n, start);
        return 0;
    }
}
