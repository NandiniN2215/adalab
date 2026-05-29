#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for edge
struct Edge {
    int src, dest, weight;
};

// Structure for subset (Union-Find)
struct Subset {
    int parent;
    int rank;
};

// Find function
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Union function
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;

    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;

    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function for sorting edges
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Kruskal Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];
    struct Subset subsets[MAX];

    int e = 0;
    int i = 0;
    int minCost = 0;

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges in MST = V-1
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Include edge if no cycle formed
        if (x != y) {
            result[e++] = nextEdge;
            minCost += nextEdge.weight;
            Union(subsets, x, y);
        }
    }

    // Print MST
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n",
               result[i].src,
               result[i].dest,
               result[i].weight);
    }

    printf("\nMinimum Cost = %d\n", minCost);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    printf("Enter source destination weight:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
