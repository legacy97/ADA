#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // number of vertices in the graph

// Find the vertex with minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra’s algorithm for a graph represented using adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // dist[i] will hold the shortest distance from src to i
    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    dijkstra(graph, 0);  // Run Dijkstra starting from vertex 0

    return 0;
}
