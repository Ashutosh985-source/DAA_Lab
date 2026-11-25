#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int weight[], int value[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // Base case
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            // Current item can fit
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]],

                    dp[i - 1][w]
                );
            }

            // Current item cannot fit
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};

    int W = 50;

    int n = sizeof(value) / sizeof(value[0]);

    int result = knapsack(W, weight, value, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}
