#include <iostream>
#include <string>
using namespace std;
 
class gnode {
	int id;
	string name;
	gnode *next;
 
	public:
		gnode() {
			id = -1;
			name = "***";
		}
	friend class graph;
};
 
class graph {
	int n;
	gnode *head[20];
	public:
		graph() {
			cout<<"Enter number of vertices: ";
			cin>>n;
			for(int i = 0; i < n; i++) {
				head[i] = new gnode;
				head[i]->id = i;
				head[i]->name = "****";
				head[i]->next = NULL;
			}
		}
 
		void createHead() {
			for(int i = 0; i < n; i++) {
					gnode *temp = head[i];
					string choice;
				do {
					int v;
					cout<<"Enter the ID adjacent to "<<i+1<<" person:";
					cin>>v;
					if(v == head[i]->id) {
						cout<<"Self loop is not allowed"<<endl;
					}
					else {				
						gnode *curr = new gnode;
						curr->id = v;
						cout<<"Enter name of "<<v<<" person:"; 
						cin>>curr->name;
						temp->next = curr;
						curr->next = NULL;
						temp = temp->next;
					}
					cout<<"Do you have person adjacent to "<<i+1<<" person (y or n):";
					cin>>choice;
				}
				while(choice == "y");
			}
		}
 
		void display() {
			for(int i = 0; i < n; i++) {
				gnode *temp = head[i];
				while(temp->next != NULL) {
					cout<<temp->id<<" "<<temp->name<<endl;
					temp = temp->next;
				}
				cout<<endl;
			}
		}
};

int main() {
	graph g1;
	g1.createHead();
	g1.display();
	
	return 0;
}

   
