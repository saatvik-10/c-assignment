// #include <bits/stdc++.h>
// using namespace std;

// class gnode {
//     int id;
//     string name;
//     gnode *next;

// public:
//     gnode() {
//         id = -1;
//         name = "***";
//         next = nullptr;
//     }
//     friend class graph;
// };

// class graph {
//     gnode *head[20];

// public:
//     int n;
//     graph() {
//         cout << "Enter number of vertices (users): ";
//         cin >> n;
//         for (int i = 0; i < n; i++) {
//             head[i] = new gnode;
//             head[i]->id = i;
//             cout << "Enter name for user " << i + 1 << ": ";
//             cin >> head[i]->name;
//             head[i]->next = nullptr;
//         }
//     }

//     void createHead() {
//         for (int i = 0; i < n; i++) {
//             gnode *temp = head[i];
//             string choice;
//             do {
//                 int v;
//                 cout << "Enter the ID of a friend of " << head[i]->name << " (0 to " << n - 1 << "): ";
//                 cin >> v;

//                 if (v == head[i]->id) {
//                     cout << "Self-loop is not allowed.\n";
//                 } else if (v < 0 || v >= n) {
//                     cout << "Invalid ID. Try again.\n";
//                 } else {
//                     gnode *curr = new gnode;
//                     curr->id = v;
//                     curr->name = head[v]->name; // Use the name from the head node
//                     curr->next = nullptr;

//                     temp->next = curr;
//                     temp = temp->next;
//                 }

//                 cout << "Do you have more friends for " << head[i]->name << "? (y or n): ";
//                 cin >> choice;
//             } while (choice == "y");
//         }
//     }

//     void display() {
//         cout << "\nFriend Network:\n";
//         for (int i = 0; i < n; i++) {
//             gnode *temp = head[i];
//             cout << temp->name << " (" << temp->id << ") --> ";
//             temp = temp->next;
//             while (temp != nullptr) {
//                 cout << temp->name << " (" << temp->id << ") ";
//                 temp = temp->next;
//                 if (temp != nullptr) cout << "-> ";
//             }
//             cout << endl;
//         }
//     }

//     void bfs(int start) {
//         cout << "\nBFS Traversal starting from " << head[start]->name << " (" << start << "):\n";
//         bool visited[n] = {false};
//         queue<int> q;

//         q.push(start);
//         visited[start] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             cout << head[node]->name << " (" << node << ") ";

//             gnode *temp = head[node]->next;
//             while (temp != nullptr) {
//                 if (!visited[temp->id]) {
//                     q.push(temp->id);
//                     visited[temp->id] = true;
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }

//     void dfs(int start) {
//         cout << "\nDFS Traversal starting from " << head[start]->name << " (" << start << "):\n";
//         bool visited[n] = {false};
//         stack<int> s;

//         s.push(start);

//         while (!s.empty()) {
//             int node = s.top();
//             s.pop();

//             if (!visited[node]) {
//                 cout << head[node]->name << " (" << node << ") ";
//                 visited[node] = true;

//                 gnode *temp = head[node]->next;
//                 while (temp != nullptr) {
//                     if (!visited[temp->id]) {
//                         s.push(temp->id);
//                     }
//                     temp = temp->next;
//                 }
//             }
//         }
//         cout << endl;
//     }
    
//     void dfs_recur(int start) {
//     		cout << "\nDFS Recursive starting from " << head[start]->name << " (" << start << "):\n";
//     		bool visited[n] = {false};
    		
//     		dfss(start, visited);
    		
//     		cout << endl;
//     }
    
//     void dfss(int node, bool visited[]) {
//     		visited[node] = true;
    		
//     		cout << head[node]->name << "(" << node << ") ";
    		
//     		gnode *temp = head[node]->next;
    		
//     		while(temp != nullptr) {
//     			if(!visited[temp->id]) {
//     				dfss(temp->id, visited);
//     			}
//     			temp = temp->next;
//     		} 
//     }
// };

// int main() {
// 	graph g1;
// 	g1.createHead();
    
//     	int choice;
// 	cout << "Choose whether you want :-\n1) BFS\n2) DFS\n3) DFS RECURSIVE\n";  
//     	cin >> choice;
    	
//     	int userId;
//     	cout << "Enter the user id to start the traversal with: " << endl;
//     	cin >> userId;
    
//     	switch(choice) {
//     		case(1):
//     			g1.bfs(userId);
//    			break;
//     		case(2):
//     			g1.dfs(userId);
//     			break;
//     		case(3):
//     			g1.dfs_recur(userId);
//     			break;
//     		default:
//     			cout << "Please select a correct option and try again!" << endl;
//     }
    
//     return 0;
// } 

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int node, vector<bool>&visited){
    visited[node] = true;
    cout<<node<<" ";
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbour = graph[node][i];
        if (!visited[i]) {
            dfs(graph,neighbour,visited); 
        }
    }
}

void bfs(vector<vector<int>>&graph,int start){
    int v = graph.size();
    vector<bool>vis(v,false);
    queue<int>q;

    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                q.push(neighbour);
            }   
        }
    }
}

int main(){
    vector<vector<int>>adj = {{2,3,1} ,{0},{0,4},{0},{2}};
    int v = adj.size();
    cout<<"DFS"<<endl;
    vector<bool>visited(v,false);
    dfs(adj,0,visited);
    
    cout<<"BFS"<<endl;
    bfs(adj,0);
    cout<<endl;
}