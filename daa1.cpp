#include <bits/stdc++.h>
using namespace std;

class user{
	private:
	string name;
	long int mobnum;
	float billamount;
	
	public:
	user(){
		name="";
		mobnum=0;
		billamount=0;
	}
	
	friend class record;
};

class record{
	public:
	 int n;
	 user uid[100];
	 void accept();
	 void linearsearchmobnum();
	 void heapify(int n, int i);
	 void heapSort();
	 void binarySearch(int n);
	 void quickSort(int l, int r);
	 void partition(int l, int r);
	 void display();
};

void record::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && uid[l].billamount > uid[largest].billamount)
        largest = l;
 
    if (r < n && uid[r].billamount > uid[largest].billamount)
        largest = r;
 
    if (largest != i) {
        swap(uid[i], uid[largest]);
 
        heapify(n, largest);
    }
}
 
void record::heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(uid[0], uid[i]);
 
        heapify(i, 0);
    }
}
	
void record::linearsearchmobnum(){
	long int data;
	cout<<"Enter the mobile number to be searched using Linear Search: "<<endl;
	cin>>data;
	for(int i=0;i<n;i++){
		if(data==uid[i].mobnum){
		cout<<"Found data is of "<<uid[i].name<<endl;
		break;
		}
	}
}

void record::binarySearch(int n) {
	long int data;

	int l = 0;
	int r = n - 1;
	
	cout<<"Enter the mobile number to be searched using Binary Search: "<<endl;
	cin>>data;
	
	while(l <= r) {
		int mid = (l + r) / 2;
		
		if(uid[mid].mobnum <= data) {
			l = mid + 1;
			cout<<"Data Found is: "<<uid[mid].name<<endl;
		} else {
			r = mid - 1;
		}
	}
}

void record::partition(int l, int r){
	long int pivot = uid[l].mobnum;
	int i = l;
	int j = r;
	
	while(i < j) {
		while(uid[i].mobnum <= pivot && pivot <= r-1) i++;
		while(uid[j].mobnum >= pivot && pivot >= l+1) j--;
		
		if(i < j) {
			swap(uid[i].mobnum, uid[j].mobnum);
		}
	}
	swap(uid[i].mobnum, uid[j].mobnum);
	return j;
}

void record::quickSort(int l, int r) {
	if(l < r) {
		int pI = partition(int l, int r);
		
		quickSort(l, pI);
		quickSort(pI+1, r);
	}
}

void record::accept(){
	cout<<"Enter the number of users: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter name of the user: ";
		cin>>uid[i].name;
		cout<<"Enter mobile number of the user: ";
		cin>>uid[i].mobnum;
		cout<<"Enter bill amount of the user: ";
		cin>>uid[i].billamount;
	}
}

void record::display(){
	for(int i=0;i<n;i++) {
		cout<<uid[i].name<<" ";
		cout<<uid[i].mobnum<<" ";
		cout<<uid[i].billamount<<" ";
		cout<<endl;
	}
}

int main(){
	record r1;
	cout<<"Accept\n";
	r1.accept();
	cout<<endl;
	cout<<"Display\n";
	r1.display();
	cout<<endl;
	cout<<"Linear Search\n";
	r1.linearsearchmobnum();
	cout<<endl;
	r1.heapSort();
	cout<<"Display after heapsort\n";
	r1.display();
	cout<<"Binary Search\n";
	r1.binarySearch(r1.n);
	cout<<endl;
	cout<<"Quick Sort\n";
	r1.quickSort(0, r1.n-1);
	cout<<endl;
	cout<<endl;
	return 0;
}




			

	
		
