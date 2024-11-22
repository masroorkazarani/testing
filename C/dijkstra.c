#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int distance[MAX], visited[MAX];
    int i, j, minDistance, nextNode;

    // Initialize distances and visited array
    for (i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[start] = 0; // Distance to the start node is 0

    for (i = 0; i < n - 1; i++)
    {
        minDistance = INF;
        nextNode = -1;

        // Find the nearest unvisited node
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                nextNode = j;
            }
        }

        if (nextNode == -1)
            break; // No more nodes to process
        visited[nextNode] = 1;

        // Update the distances of the neighbors of the chosen node
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[nextNode][j] != 0 &&
                distance[nextNode] + graph[nextNode][j] < distance[j])
            {
                distance[j] = distance[nextNode] + graph[nextNode][j];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from node %d:\n", start);
    for (i = 0; i < n; i++)
    {
        printf("To node %d: %d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX][MAX], n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node (0-based index): ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
