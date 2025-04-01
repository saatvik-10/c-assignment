#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using DP
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));

    // Initialize first row and first column to 0 (already done by vector default initialization)
    
    // Fill the DP table based on the given pseudocode
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) { // Item can be included
                if (values[i - 1] + B[i - 1][w - weights[i - 1]] > B[i - 1][w]) {
                    B[i][w] = values[i - 1] + B[i - 1][w - weights[i - 1]];
                } else {
                    B[i][w] = B[i - 1][w];
                }
            } else {
                B[i][w] = B[i - 1][w]; // Item cannot be included
            }
        }
    }

    return B[n][W]; // Maximum value that can be obtained
}

// Driver code to take dynamic input
int main() {
    int n, W;
    
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack: " << max_value << endl;

    return 0;
}
