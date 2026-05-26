#include <stdio.h>

int findTargetSumWays(int nums[], int n, int target) {
    int sum = 0;

    // Calculate total sum
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    // Edge cases
    if ((target + sum) % 2 != 0 || sum < target || sum < -target) {
        return 0;
    }

    int subsetSum = (target + sum) / 2;

    // DP array
    int dp[subsetSum + 1];

    // Initialize DP array
    for (int i = 0; i <= subsetSum; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    // Count subsets
    for (int i = 0; i < n; i++) {
        for (int j = subsetSum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[subsetSum];
}

int main() {
    int nums[] = {1, 1, 1, 1, 1};
    int target = 3;

    int n = sizeof(nums) / sizeof(nums[0]);

    int ways = findTargetSumWays(nums, n, target);

    printf("Number of ways = %d\n", ways);

    return 0;
}
