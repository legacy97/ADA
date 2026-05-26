#include <stdio.h>
#define INF 99999
#define V 4   // Number of vertices

// Function to print the solution
void printSolution(int dist[V][V]) {
    printf("All-Pairs Shortest Paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix same as input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update distances considering each vertex as an intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(graph);
    return 0;
}
