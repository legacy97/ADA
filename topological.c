#include <stdio.h>

#define MAX 100

void printGraph(int V[MAX][MAX], int n) {
    printf("\nGraph (Adjacency Matrix):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", V[i][j]);
        }
        printf("\n");
    }
}

void topoSort(int V[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (V[j][i] == 1)
                indegree[i]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        topo[k++] = u;

        for (int v = 0; v < n; v++) {
            if (V[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    printf("\nTopological Order: ");
    if (k != n) {
        printf("Cycle exists\n");
    } else {
        for (int i = 0; i < k; i++)
            printf("%d ", topo[i]);
    }
}

int main() {
    int n = 4;

    int V[MAX][MAX] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };

    printGraph(V, n);   // 👈 GRAPH OUTPUT
    topoSort(V, n);

    return 0;
}
