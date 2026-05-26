#include <stdio.h>

#define MAX 100

int canFinish(int n, int prereq[][2], int m) {
    int indegree[MAX] = {0};
    int adj[MAX][MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    for (int i = 0; i < m; i++) {
        int a = prereq[i][0];
        int b = prereq[i][1];
        adj[b][a] = 1;
        indegree[a]++;
    }

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    return count == n;
}

int main() {
    int n = 4;
    int prereq[3][2] = {{1,0},{2,0},{3,1}};

    printf("%s\n", canFinish(n, prereq, 3) ? "true" : "false");
    return 0;
}
