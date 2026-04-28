#include <stdio.h>
#include <stdlib.h>


// Function for Topological Sort
void topologicalSort(int **adj, int n) {
    int *indegree = (int *)calloc(n, sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int count = 0;

    // Compute indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j])
                indegree[j]++;
        }
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological Order: ");
     while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        // Reduce indegree of adjacent vertices
        for (int j = 0; j < n; j++) {
            if (adj[v][j]) {
                if (--indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    if (count != n)
        printf("\nGraph contains a cycle!\n");

    free(indegree);
    free(queue);
}


int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        adj[i] = (int *)malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);   // ✅ fixed here

    topologicalSort(adj, n);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;}

