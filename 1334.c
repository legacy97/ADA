#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int dist[MAX][MAX];

    // Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int resultCity = -1;
    int minCount = INT_MAX;

    // Count reachable cities
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold)
                count++;
        }

        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}

int main() {
    int n = 4;
    int edges[][3] = {{0,1,3},{1,2,1},{2,3,4},{0,3,7}};
    int edgesSize = 4;
    int threshold = 4;

    int result = findTheCity(n, edges, edgesSize, threshold);
    printf("Output: %d\n", result);

    return 0;
}
