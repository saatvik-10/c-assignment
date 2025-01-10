#include <bits/stdc++.h>
using namespace std;

class user {
private:
    string name;
    long int mobnum;
    float billamount;

public:
    user() {
        name = "";
        mobnum = 0;
        billamount = 0;
    }

    friend class record;
};

class record {
public:
    int n;
    user uid[100];
    void accept();
    void display();
    void linearSearch();
    void heapify(int n, int i);
    void heapSort();
    void binarySearch();
    void binarySearch_recursive(int l, int r, long int data);
    int partition(int l, int r);
    void quickSort(int l, int r);
};

void record::accept() {
    cout << "Enter the number of users: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of the user: ";
        cin >> uid[i].name;
        cout << "Enter mobile number of the user: ";
        cin >> uid[i].mobnum;
        cout << "Enter bill amount of the user: ";
        cin >> uid[i].billamount;
    }
}

void record::display() {
    for (int i = 0; i < n; i++) {
        cout << uid[i].name << " ";
        cout << uid[i].mobnum << " ";
        cout << uid[i].billamount << endl;
    }
}

void record::linearSearch() {
    long int data;
    int flag = 0;
    cout << "Enter the mobile number to search using Linear Search: ";
    cin >> data;
    for (int i = 0; i < n; i++) {
        if (data == uid[i].mobnum) {
            cout << "Found user: " << uid[i].name << " with bill amount: " << uid[i].billamount << endl;
            flag = 1;
            return;
        }
    }

    if(flag = 0) cout << "User not found!" << endl;

    cout << "Mobile number not found!" << endl;
}

void record::binarySearch_recursive(int l, int r, long int data) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (uid[mid].mobnum == data) {
            cout << "Found user: " << uid[mid].name << " with bill amount: " << uid[mid].billamount << endl;
            return;
        } else if (uid[mid].mobnum < data) {
            binarySearch_recursive(mid + 1, r, data);
        } else {
            binarySearch_recursive(l, mid - 1, data);
        }
    } else {
        cout << "Mobile number not found!" << endl;
    }
}

void record::binarySearch() {
    long int data;
    int l = 0, r = n - 1;
    cout << "Enter the mobile number to search using Binary Search: ";
    cin >> data;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (uid[mid].mobnum == data) {
            cout << "Found user: " << uid[mid].name << " with bill amount: " << uid[mid].billamount << endl;
            return;
        } else if (uid[mid].mobnum < data) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "Mobile number not found!" << endl;
}

void record::heapify(int n, int i) {
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

void record::heapSort() {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(uid[0], uid[i]);
        heapify(i, 0);
    }
}

int record::partition(int l, int r) {
    long int pivot = uid[l].mobnum;
    int i = l;
    int j = r;

    while (i < j) {
        while (uid[i].mobnum <= pivot) i++;
        while (uid[j].mobnum > pivot) j--;

        if (i < j) {
            swap(uid[i], uid[j]);
        }
    }
    swap(uid[l], uid[j]);
    return j;
}

void record::quickSort(int l, int r) {
    if (l < r) {
        int pI = partition(l, r);
        quickSort(l, pI - 1);
        quickSort(pI + 1, r);
    }
}

int main() {
    record r1;
    int choice;

    cout << "Accept User Records:\n";
    r1.accept();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Linear Search by Mobile Number\n";
        cout << "2. Heap Sort by Bill Amount\n";
        cout << "3. Quick Sort by Mobile Number\n";
        cout << "4. Binary Search by Mobile Number (Iterative)\n";
        cout << "5. Binary Search by Mobile Number (Recursive)\n";
        cout << "6. Display All Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                r1.linearSearch();
                break;
            case 2:
                r1.heapSort();
                cout << "Data sorted by bill amount using Heap Sort:\n";
                r1.display();
                break;
            case 3:
                r1.quickSort(0, r1.n - 1);
                cout << "Data sorted by mobile number using Quick Sort:\n";
                r1.display();
                break;
            case 4:
                r1.binarySearch();
                break;
            case 5: {
                long int data;
                cout << "Enter the mobile number to search using Recursive Binary Search: ";
                cin >> data;
                r1.binarySearch_recursive(0, r1.n - 1, data);
                break;
            }
            case 6:
                cout << "Displaying all records:\n";
                r1.display();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
