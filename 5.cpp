#include <iostream>
using namespace std;
 
#define MAX 10
 
class record {
    int rollno, marks;
    friend class student;
};
 
class hashing {
    int roll, pos;
 
public:
    hashing() {
        roll = -1;
        pos = -1;
    }
 
    friend class student;
};
 
class student {
    record rec;
    hashing h[MAX];
    int s;
 
public:
    student() {
        s = 0;
    }
 
    void create_wr(); 
    void create_wor(); 
};
 
void student::create_wr() {
    cout << "\n--- Hashing With Replacement ---\n";
    cout << "Enter number of records: ";
    cin >> s;
 
    for (int i = 0; i < s; i++) {
        cout << "\nEnter roll number and marks: ";
        cin >> rec.rollno >> rec.marks;
 
        int loc = rec.rollno % MAX;
 
        if (h[loc].roll == -1) {
            h[loc].roll = rec.rollno;
            h[loc].pos = i;
        } else {
            int temp_roll = rec.rollno;
            int temp_pos = i;
 
            if (loc != (h[loc].roll % MAX)) {
               
                temp_roll = h[loc].roll;
                temp_pos = h[loc].pos;
 
                h[loc].roll = rec.rollno;
                h[loc].pos = i;
            }
 
            int j = (loc + 1) % MAX;
            while (j != loc) {
                if (h[j].roll == -1) {
                    h[j].roll = temp_roll;
                    h[j].pos = temp_pos;
                    break;
                }
                j = (j + 1) % MAX;
            }
 
            if (j == loc) {
                cout << "Hash table is full!\n";
            }
        }
    }

    cout << "\nHash Table (With Replacement):\nIndex\tRoll\tPos\n";
    for (int i = 0; i < MAX; i++) {
        if (h[i].roll != -1)
            cout << i << "\t" << h[i].roll << "\t" << h[i].pos << "\n";
        else
            cout << i << "\tEmpty\t-\n";
    }
}
 

void student::create_wor() {
    cout << "\n--- Hashing Without Replacement ---\n";
    cout << "Enter number of records: ";
    cin >> s;
 
    for (int i = 0; i < s; i++) {
        cout << "\nEnter roll number and marks: ";
        cin >> rec.rollno >> rec.marks;
 
        int loc = rec.rollno % MAX;
 
        int j = loc;
        while (h[j].roll != -1) {
            j = (j + 1) % MAX;
            if (j == loc) {
                cout << "Hash table is full!\n";
                break;
            }
        }
 
        if (h[j].roll == -1) {
            h[j].roll = rec.rollno;
            h[j].pos = i;
        }
    }
 

    cout << "\nHash Table (Without Replacement):\nIndex\tRoll\tPos\n";
    for (int i = 0; i < MAX; i++) {
        if (h[i].roll != -1)
            cout << i << "\t" << h[i].roll << "\t" << h[i].pos << "\n";
        else
            cout << i << "\tEmpty\t-\n";
    }
}
 

int main() {
    student s;
    int ch;
 
    do {
        cout << "\nMenu:\n1. With Replacement\n2. Without Replacement\n3. Exit\nEnter choice: ";
        cin >> ch;
 
        switch (ch) {
            case 1: s.create_wr(); break;
            case 2: s.create_wor(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 3);
 
    return 0;
}