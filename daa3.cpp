#include <bits/stdc++.h>

using namespace std;

class graph {
	int cost[10][10];
	int cities;
	
	public:
		graph() {
			cout << "Enter the number of cities: " << endl;
			cin >> cities;
			
			for(int i = 0; i < cities; i++) {
				for(int j = 0; j < cities; j++) {
					cost[i][j] = 999;
				}
			}
		}
	void create();
	void display();
	int prims_algo(int st);
};

void graph :: create() {
	char ch;
	
	for(int i = 0; i < cities; i++) {
		for(int j = 0; j < cities; j++) {
			if(cost[j][i] == 999 && i != j) {
				cout << endl << "Is there a connection between" << i << "and" << j << "? (y or no): " ;
				cin >> ch;
				if(ch == 'y') {
					cout << "Enter the cost of edge: ";
					cin >> cost[i][j];
					cost[j][i] = cost[i][j];
				}
			}
		}
	}
}

void graph :: display() {
	for(int i = 0; i < cities; i++) {
		for(int j = 0; j < cities; j++) {
			cout << " " << cost[i][j] << " ";
		}
		cout << endl;
	}
}

int graph :: prims_algo(int st) {
	int nearest[cities];
	int n = cities;
	int t[cities][3];
	int r = 0;
	int min = 999;
	int minCost = 0;
	int index;
	
	nearest[st] = -1;
	
	for(int i = 0; i <= n; i++) {
		if(i != st) {
			nearest[i] = st;
		}
	}
	
	for(int i = 0; i < n - 1; i++) {
		min = 999;
		for(int j = 0; j < n; j++) {
			if(nearest[j] != -1 && (cost[j][nearest[j]]) < min) {
				index = j;
				min =cost[j][nearest[j]];
			}
		}
		t[r][0] = nearest[index];
		t[r][1] = index;
		t[r][2] = min;
		r++;
		
		minCost += cost[index][nearest[index]];
		nearest[index] = -1;
		
		for(int i = 0; i < n - 1; i++) {
			if(nearest[i] != -1 && (cost[i, nearest[i]] > cost[i, index])) {
				nearest[i] = index;
			} 
		}
	}
	return minCost;
}

int main() {
    graph g;
    int choice, st;

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept (Create graph)\n";
        cout << "2. Display (Show adjacency matrix)\n";
        cout << "3. Prims Algo (Find Minimum Spanning Tree)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Enter the starting vertex for Prim's Algorithm: ";
                cin >> st;
                if(st < 0 || st >= g.cities) {
                    cout << "Error: Invalid vertex.\n";
                } else {
                    g.prims_algo(st);
                }
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
