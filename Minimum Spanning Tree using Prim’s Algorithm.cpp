#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Function to find the minimum key vertex
int findMinKeyVertex(int key[], bool mstSet[], int n) {
    int minKey = __INT_MAX__, minIndex;
    
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX_NODES][MAX_NODES], int n) {
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_NODES][MAX_NODES], int n) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];
    
    // Initialize key values and MST set
    for (int i = 0; i < n; i++) {
        key[i] = __INT_MAX__;
        mstSet[i] = false;
    }
    
    key[0] = 0; // Start from the first vertex
    parent[0] = -1; // First node is always the root of MST
    
    for (int count = 0; count < n - 1; count++) {
        int u = findMinKeyVertex(key, mstSet, n);
        mstSet[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, n);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    primMST(graph, n);
    
    return 0;
}

