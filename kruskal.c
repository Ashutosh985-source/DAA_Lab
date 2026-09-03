#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main() {
    int n, e;
    int u[20], v[20], w[20];
    int i, j, temp;
    int count = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");

    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    // Initially, every vertex is its own parent
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Sort edges according to weight
    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (w[i] > w[j]) {
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = u[i];
                u[i] = u[j];
                u[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Kruskal's algorithm
    for (i = 0; i < e && count < n - 1; i++) {

        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b) {
            printf("%d - %d = %d\n", u[i], v[i], w[i]);

            total += w[i];
            unionSet(a, b);
            count++;
        }
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}
