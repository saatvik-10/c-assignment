#include <iostream>
#include <cmath>
using namespace std;

int x[20]; // Array to store queen positions
int n; // Number of queens

bool Place(int r, int c) {  
    for (int i = 1; i < r; i++) {  
        if (x[i] == c || abs(x[i] - c) == abs(i - r))  
            return false;  // Conflict found
    }
    return true;  // Safe to place queen
}

void PrintSolution() {
    cout << "Solution:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << "---------------------\n";
}

void NQueen(int r) {  
    for (int i = 1; i <= n; i++) {  
        if (Place(r, i)) {  
            x[r] = i;  // Place queen
            if (r == n)  
                PrintSolution();  // Found solution
            else  
                NQueen(r + 1);  // Move to next row
        }
    }
}

int main() {
    cout << "Enter the number of queens (n): ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid input! Number of queens must be at least 1.\n";
        return 0;
    }

    NQueen(1);  // Start placing queens from row 1

    return 0;
}
