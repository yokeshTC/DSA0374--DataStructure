#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100


struct Node {
    int value;
    struct Node* next;
};


struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};


void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}


void BFS(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};

    
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    
    queue[rear++] = startNode;
    visited[startNode] = 1; 

    printf("Breadth First Traversal starting from node %d:\n", startNode);

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        
        struct Node* temp = graph->adjList[currentNode];
        while (temp != NULL) {
            int adjNode = temp->value;
            if (!visited[adjNode]) {
                queue[rear++] = adjNode;
                visited[adjNode] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes, numEdges;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    
    graph.numNodes = numNodes;
    

    for (int i = 0; i < numNodes; i++) {
        graph.adjList[i] = NULL;
    }
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge #%d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    
    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);
    
    BFS(&graph, startNode);
    
    return 0;
}

