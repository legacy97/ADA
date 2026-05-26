#include <stdio.h>

#define MAX 2000

int indegree[MAX];
int adj[MAX][MAX];
int queue[MAX];
int order[MAX];

int* findOrder(int numCourses, int prerequisites[][2], int prereqSize, int* returnSize) {

    int front = 0, rear = 0;
    int idx = 0;

    // reset arrays
    for (int i = 0; i < numCourses; i++) {
        indegree[i] = 0;
        for (int j = 0; j < numCourses; j++) {
            adj[i][j] = 0;
        }
    }

    // build graph
    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][a] = 1;
        indegree[a]++;
    }

    // push indegree 0 nodes
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // BFS (Kahn's algorithm)
    while (front < rear) {
        int node = queue[front++];
        order[idx++] = node;

        for (int i = 0; i < numCourses; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // cycle check
    if (idx != numCourses) {
        *returnSize = 0;
        return order;
    }

    *returnSize = idx;
    return order;
}

// test
int main() {
    int numCourses = 4;
    int prerequisites[3][2] = {{1,0},{2,0},{3,1}};

    int returnSize;

    int* ans = findOrder(numCourses, prerequisites, 3, &returnSize);

    if (returnSize == 0) {
        printf("[]\n");
        return 0;
    }

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
