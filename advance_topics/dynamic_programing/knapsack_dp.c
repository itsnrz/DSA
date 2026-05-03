#include <stdio.h>

/*
Function: Knapsack
Purpose: Solve 0/1 Knapsack using Dynamic Programming

Parameters:
m → item array
n → number of items
W → capacity
dp → DP table (created in main)

Returns:
Maximum profit
*/
double Knapsack(double m[][3], int n, int W, int dp[n+1][W+1]) {

    /*
    dp[i][w] →
    max profit using first i items with capacity w
    */

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            // BASE CASE
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else {
                int wt = (int)m[i-1][1];
                int val = (int)m[i-1][2];

                if(wt <= w) {
                    int include = val + dp[i-1][w - wt];
                    int exclude = dp[i-1][w];

                    dp[i][w] = (include > exclude) ? include : exclude;
                }
                else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
    }

    return dp[n][W];
}

/*
Function: printSelectedItems
Purpose: Backtrack DP table to find selected items
*/
void printSelectedItems(double m[][3], int n, int W, int dp[n+1][W+1]) {

    int w = W;

    printf("\nSelected Items:\n");

    for(int i = n; i > 0; i--) {

        // If value changed → item included
        if(dp[i][w] != dp[i-1][w]) {

            printf("Item %d (Weight = %.0lf, Value = %.0lf)\n",
                   (int)m[i-1][0], m[i-1][1], m[i-1][2]);

            w -= (int)m[i-1][1]; // reduce capacity
        }
    }
}

int main() {

    int n, capacity;

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    /*
    Item array:
    [0] → item number
    [1] → weight
    [2] → value
    */
    double arr[n][3];

    for(int i = 0; i < n; i++) {
        printf("\nItem %d\n", i+1);

        printf("Item no: ");
        scanf("%lf", &arr[i][0]);

        printf("Weight: ");
        scanf("%lf", &arr[i][1]);

        printf("Value: ");
        scanf("%lf", &arr[i][2]);
    }

    /*
    DP TABLE CREATED IN MAIN (as you asked)
    */
    int dp[n+1][capacity+1];

    // Compute max profit
    double profit = Knapsack(arr, n, capacity, dp);

    printf("\nMaximum Profit = %.0lf\n", profit);

    // Print selected items
    printSelectedItems(arr, n, capacity, dp);

    return 0;
}