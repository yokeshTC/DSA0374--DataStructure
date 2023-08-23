#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0; 
    int i = 0; 

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destination);

        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d, Weight: %d\n", result[i].source, result[i].destination, result[i].weight);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; ++i) {
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &graph->edges[i].source, &graph->edges[i].destination, &graph->edges[i].weight);
    }

    kruskalMST(graph);

    free(graph->edges);
    free(graph);

    return 0;
}

