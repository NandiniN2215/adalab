#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int dist[MAX];   // <-- declare dist array
    int i, j, u, min, start;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use 9999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize distances
    for (i = 0; i < n; i++)
        dist[i] = cost[start][i];
    visited[start] = 1;
    dist[start] = 0;

    // Dijkstra’s algorithm
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];   // <-- update distance
            }
        }
    }

    printf("Shortest distance from vertex %d:\n", start);
    for (i = 0; i < n; i++)
        printf("to %d = %d\n", i, dist[i]);

    return 0;
}

