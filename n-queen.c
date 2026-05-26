#include <stdio.h>

#define MAX 20

int board[MAX];
int solutionCount = 0;

// Check whether queen placement is safe
int isSafe(int row, int col) {

    for (int i = 0; i < row; i++) {

        // Same column
        if (board[i] == col)
            return 0;

        // Diagonal check
        if ((board[i] - col == i - row) ||
            (board[i] - col == row - i))
            return 0;
    }

    return 1;
}

// Print one solution
void printBoard(int n) {

    printf("\nSolution %d:\n\n", ++solutionCount);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }

        printf("\n");
    }
}

// Backtracking function
void solveNQueens(int row, int n) {

    // If all queens placed
    if (row == n) {
        printBoard(n);
        return;
    }

    // Try each column
    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row] = col;

            solveNQueens(row + 1, n);
        }
    }
}

int main() {

    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    solveNQueens(0, n);

    if (solutionCount == 0)
        printf("No solution exists.\n");
    else
        printf("\nTotal Solutions = %d\n", solutionCount);

    return 0;
}
