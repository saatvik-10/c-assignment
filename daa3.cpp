#include <bits/stdc++.h>

using namespace std;

class graph {
    int cost[10][10];

public:
    int cities;
    graph() {
        cout << "Enter the number of cities: ";
        cin >> cities;

        for (int i = 0; i < cities; i++) {
            for (int j = 0; j < cities; j++) {
                cost[i][j] = 999; // Initialize with a large value (infinity)
            }
        }
    }
    void create();
    void display();
    int prims_algo(int st);
};

void graph::create() {
    char ch;

    for (int i = 0; i < cities; i++) {
        for (int j = i + 1; j < cities; j++) {  // Avoid redundant input
            cout << "Is there a connection between " << i << " and " << j << "? (y/n): ";
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter the cost of edge: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j]; // Make it undirected
            }
        }
    }
}

void graph::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            if (cost[i][j] == 999)
                cout << " ∞ ";
            else
                cout << " " << cost[i][j] << " ";
        }
        cout << endl;
    }
}

int graph::prims_algo(int st) {
    int nearest[10];
    bool inMST[10] = {false}; // Track included vertices
    int minEdge[10];
    int minCost = 0;

    for (int i = 0; i < cities; i++) {
        nearest[i] = -1;
        minEdge[i] = 999;
    }

    minEdge[st] = 0;

    for (int i = 0; i < cities; i++) {
        int min = 999, index = -1;

        // Find the vertex with the minimum edge cost
        for (int j = 0; j < cities; j++) {
            if (!inMST[j] && minEdge[j] < min) {
                min = minEdge[j];
                index = j;
            }
        }

        if (index == -1) {
            cout << "Graph is disconnected, MST not possible.\n";
            return -1;
        }

        inMST[index] = true;
        minCost += min;

        if (nearest[index] != -1)
            cout << "Edge: " << nearest[index] << " - " << index << " Cost: " << min << endl;

        // Update the minimum edge cost for adjacent vertices
        for (int j = 0; j < cities; j++) {
            if (!inMST[j] && cost[index][j] < minEdge[j]) {
                minEdge[j] = cost[index][j];
                nearest[j] = index;
            }
        }
    }

    cout << "Total Minimum Cost: " << minCost << endl;
    return minCost;
}

int main() {
    graph g;
    int choice, st;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. Find Minimum Spanning Tree (Prim’s Algorithm)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Enter the starting vertex (0 to " << g.cities - 1 << "): ";
                cin >> st;
                if (st < 0 || st >= g.cities)
                    cout << "Error: Invalid vertex.\n";
                else
                    g.prims_algo(st);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
