#include <stdio.h>
#include <limits.h>

#define V 5

// Find the unvisited vertex with minimum distance
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V];

    // Initialize distances
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Find shortest paths
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        // Remaining vertices are unreachable
        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tShortest Distance\n");

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}
