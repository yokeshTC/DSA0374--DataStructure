#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; 
}

void dijkstra(int source) {
    int distances[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[source] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        int minDistance = INT_MAX;
        int minVertex = -1;

        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minVertex = j;
            }
        }

        if (minVertex == -1) {
            break;
        }

        visited[minVertex] = true;

        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && graph[minVertex][j] != 0) {
                int newDistance = distances[minVertex] + graph[minVertex][j];
                if (newDistance < distances[j]) {
                    distances[j] = newDistance;
                }
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }
}

int main() {
    initializeGraph();

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}

