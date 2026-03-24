#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define INF INT_MAX

typedef struct
{
    int src, dest, weight;
} Edge;

void bellmanFord(Edge edges[], int vertices, int edgeCount, int source)
{
    int distance[MAX_VERTICES];

    // Initialize distances
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INF;
    }
    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < vertices - 1; i++)
    {
        for (int j = 0; j < edgeCount; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check negative cycle
    for (int j = 0; j < edgeCount; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INF && distance[v] > distance[u] + w)
        {
            printf("Negative cycle detected\n");
            return;
        }
    }

    // Print result
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main()
{
    int vertices = 6;
    int edgeCount = 8;

    Edge edges[] = {
        {0, 1, 5}, {0, 2, 7}, {1, 2, 3}, {1, 3, 4}, {1, 4, 6}, {3, 4, -1}, {3, 5, 2}, {4, 5, -3}};

    bellmanFord(edges, vertices, edgeCount, 0);

    return 0;
}