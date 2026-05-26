#include <stdio.h>

int main() {
    int a[10][10], i, j, n, sum = 0;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Sum of left diagonal elements
    for(i = 0; i < n; i++) {
        sum = sum + a[i][i];
    }

    printf("Sum of left diagonal elements = %d", sum);

    return 0;
}
