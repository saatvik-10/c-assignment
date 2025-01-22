#include <bits/stdc++.h>
using namespace std;

class gnode {
    int id;
    string name;
    gnode *next;

public:
    gnode() {
        id = -1;
        name = "***";
        next = nullptr;
    }
    friend class graph;
};

class graph {
    gnode *head[20];

public:
    int n;
    graph() {
        cout << "Enter number of vertices (users): ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            head[i] = new gnode;
            head[i]->id = i;
            cout << "Enter name for user " << i + 1 << ": ";
            cin >> head[i]->name;
            head[i]->next = nullptr;
        }
    }

    void createHead() {
        for (int i = 0; i < n; i++) {
            gnode *temp = head[i];
            string choice;
            do {
                int v;
                cout << "Enter the ID of a friend of " << head[i]->name << " (0 to " << n - 1 << "): ";
                cin >> v;

                if (v == head[i]->id) {
                    cout << "Self-loop is not allowed.\n";
                } else if (v < 0 || v >= n) {
                    cout << "Invalid ID. Try again.\n";
                } else {
                    gnode *curr = new gnode;
                    curr->id = v;
                    curr->name = head[v]->name; // Use the name from the head node
                    curr->next = nullptr;

                    temp->next = curr;
                    temp = temp->next;
                }

                cout << "Do you have more friends for " << head[i]->name << "? (y or n): ";
                cin >> choice;
            } while (choice == "y");
        }
    }

    void display() {
        cout << "\nFriend Network:\n";
        for (int i = 0; i < n; i++) {
            gnode *temp = head[i];
            cout << temp->name << " (" << temp->id << ") --> ";
            temp = temp->next;
            while (temp != nullptr) {
                cout << temp->name << " (" << temp->id << ") ";
                temp = temp->next;
                if (temp != nullptr) cout << "-> ";
            }
            cout << endl;
        }
    }

    void bfs(int start) {
        cout << "\nBFS Traversal starting from " << head[start]->name << " (" << start << "):\n";
        bool visited[n] = {false};
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << head[node]->name << " (" << node << ") ";

            gnode *temp = head[node]->next;
            while (temp != nullptr) {
                if (!visited[temp->id]) {
                    q.push(temp->id);
                    visited[temp->id] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void dfs(int start) {
        cout << "\nDFS Traversal starting from " << head[start]->name << " (" << start << "):\n";
        bool visited[n] = {false};
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << head[node]->name << " (" << node << ") ";
                visited[node] = true;

                gnode *temp = head[node]->next;
                while (temp != nullptr) {
                    if (!visited[temp->id]) {
                        s.push(temp->id);
                    }
                    temp = temp->next;
                }
            }
        }
        cout << endl;
    }
    
    void dfs_recur(int start) {
    		cout << "\nDFS Recursive starting from " << head[start]->name << " (" << start << "):\n";
    		bool visited[n] = {false};
    		
    		dfss(start, visited);
    		
    		cout << endl;
    }
    
    void dfss(int node, bool visited[]) {
    		visited[node] = true;
    		
    		cout << head[node]->name << "(" << node << ") ";
    		
    		gnode *temp = head[node]->next;
    		
    		while(temp != nullptr) {
    			if(!visited[temp->id]) {
    				dfss(temp->id, visited);
    			}
    			temp = temp->next;
    		} 
    }
};

int main() {
    graph g1;
    g1.createHead();
    g1.display();

    int startNode;
    cout << "Enter the starting node ID for BFS and DFS: ";
    cin >> startNode;

    if (startNode >= 0 && startNode < g1.n) {
        g1.bfs(startNode);
        g1.dfs(startNode);
        g1.dfs_recur(startNode);
    } else {
        cout << "Invalid starting node.\n";
    }

    return 0;
}
