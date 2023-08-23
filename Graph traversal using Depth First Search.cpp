#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100


int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

int numNodes;

void initializeGraph() {
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1; 
}

void depthFirstSearch(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            depthFirstSearch(i);
        }
    }
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeGraph();

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int from, to;
        printf("Enter edge %d (from to): ", i + 1);
        scanf("%d %d", &from, &to);
        addEdge(from, to);
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("Depth First Search starting from node %d: ", startNode);
    depthFirstSearch(startNode);
    printf("\n");

    return 0;
}

