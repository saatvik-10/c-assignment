#include <bits/stdc++.h>
using namespace std;

struct User {
    string name;
    long int mobnum;
    float billamount;
};

int n;
User users[100];

void accept() {
    cout << "Enter the number of users: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of the user: ";
        cin >> users[i].name;
        cout << "Enter mobile number of the user: ";
        cin >> users[i].mobnum;
        cout << "Enter bill amount of the user: ";
        cin >> users[i].billamount;
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        cout << users[i].name << " ";
        cout << users[i].mobnum << " ";
        cout << users[i].billamount << endl;
    }
}

void linearSearch() {
    long int data;
    int flag = 0;
    cout << "Enter the mobile number to search using Linear Search: ";
    cin >> data;
    for (int i = 0; i < n; i++) {
        if (data == users[i].mobnum) {
            cout << "Found user: " << users[i].name << " with bill amount: " << users[i].billamount << endl;
            return;
        }
    }
    cout << "Mobile number not found!" << endl;
}

void binarySearch_recursive(int l, int r, long int data) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (users[mid].mobnum == data) {
            cout << "Found user: " << users[mid].name << " with bill amount: " << users[mid].billamount << endl;
            return;
        } else if (users[mid].mobnum < data) {
            binarySearch_recursive(mid + 1, r, data);
        } else {
            binarySearch_recursive(l, mid - 1, data);
        }
    } else {
        cout << "Mobile number not found!" << endl;
    }
}

void binarySearch() {
    long int data;
    int l = 0, r = n - 1;
    cout << "Enter the mobile number to search using Binary Search: ";
    cin >> data;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (users[mid].mobnum == data) {
            cout << "Found user: " << users[mid].name << " with bill amount: " << users[mid].billamount << endl;
            return;
        } else if (users[mid].mobnum < data) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "Mobile number not found!" << endl;
}

int partition(int l, int r) {
    long int pivot = users[l].mobnum;
    int i = l;
    int j = r;

    while (i < j) {
        while (users[i].mobnum <= pivot && i < r) i++;
        while (users[j].mobnum > pivot) j--;

        if (i < j) {
            swap(users[i], users[j]);
        }
    }
    swap(users[l], users[j]);
    return j;
}

void quickSort(int l, int r) {
    if (l < r) {
        int pI = partition(l, r);
        quickSort(l, pI - 1);
        quickSort(pI + 1, r);
    }
}

int main() {
    int choice;

    cout << "Accept User Records:\n";
    accept();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Linear Search by Mobile Number\n";
        cout << "2. Quick Sort by Mobile Number\n";
        cout << "3. Binary Search by Mobile Number (Iterative)\n";
        cout << "4. Binary Search by Mobile Number (Recursive)\n";
        cout << "5. Display All Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                linearSearch();
                break;
            case 2:
                quickSort(0, n - 1);
                cout << "Data sorted by mobile number using Quick Sort:\n";
                display();
                break;
            case 3:
                binarySearch();
                break;
            case 4: {
                long int data;
                cout << "Enter the mobile number to search using Recursive Binary Search: ";
                cin >> data;
                binarySearch_recursive(0, n - 1, data);
                break;
            }
            case 5:
                cout << "Displaying all records:\n";
                display();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
