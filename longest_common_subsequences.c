
#include <stdio.h>                        //Ujjawal roy
                                          //25/DA/061                  
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[MAX], profit[MAX];
    int dp[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter weight and profit of each item:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum profit: %d\n", dp[n][capacity]);

    return 0;
}
