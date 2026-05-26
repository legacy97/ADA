#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // Base condition
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // If item can be included
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            // Item cannot be included
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);

    printf("Maximum value in knapsack = %d\n", result);

    return 0;
}
