#include <iostream>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// A Dynamic Programming based solution for 0-1 Knapsack problem
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w,
        K[n + 1][W + 1];
 
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int knapSackRecursion(int W, int wt[], int val[], int n) {
    if (n < 0) {
        return 0;
    }
    if (wt[n] > W)
        return knapSackRecursion(W, wt, val, n-1);
    else {
        return max(knapSackRecursion(W, wt, val, n-1), knapSackRecursion(W - wt[n], wt, val, n-1) + val[n]);
    }
}

int main(){
    int W = 50,
        n = 3,
        val[] = { 60, 100, 120 },
        wt[] = { 10, 20, 30 };
    
    
    cout << knapSack(W, wt, val, n) << endl;
    cout << knapSackRecursion(W, wt, val, n)<< endl;
 
    return 0;
}