#include <iostream>
#include <string>
using namespace std;

class avl_node {
public:
    string word, meaning;
    avl_node* left, * right;

    avl_node(string w, string m) {
        word = w;
        meaning = m;
        left = right = nullptr;
    }
};

class avlTree {
    avl_node* root;

public:
    avlTree() {
        root = nullptr;
    }

    int height(avl_node*);
    int diff(avl_node*);
    avl_node* rr_rotation(avl_node*);
    avl_node* ll_rotation(avl_node*);
    avl_node* lr_rotation(avl_node*);
    avl_node* rl_rotation(avl_node*);
    avl_node* balance(avl_node*);
    avl_node* insert(avl_node*, avl_node*);
    void insert();
    void display(avl_node*, int);
    void display(); // Wrapper for display()
};

// Calculate height of a node
int avlTree::height(avl_node* temp) {
    if (temp == nullptr)
        return 0;
    return max(height(temp->left), height(temp->right)) + 1;
}

// Compute balance factor
int avlTree::diff(avl_node* temp) {
    return height(temp->left) - height(temp->right);
}

// Right-Right Rotation
avl_node* avlTree::rr_rotation(avl_node* parent) {
    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left-Left Rotation
avl_node* avlTree::ll_rotation(avl_node* parent) {
    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// Left-Right Rotation
avl_node* avlTree::lr_rotation(avl_node* parent) {
    parent->left = rr_rotation(parent->left);
    return ll_rotation(parent);
}

// Right-Left Rotation
avl_node* avlTree::rl_rotation(avl_node* parent) {
    parent->right = ll_rotation(parent->right);
    return rr_rotation(parent);
}

// Balance the tree
avl_node* avlTree::balance(avl_node* temp) {
    int bal_factor = diff(temp);
    if (bal_factor > 1) {
        if (diff(temp->left) >= 0) {
            temp = ll_rotation(temp);
        } else {
            temp = lr_rotation(temp);
        }
    } else if (bal_factor < -1) {
        if (diff(temp->right) <= 0) {
            temp = rr_rotation(temp);
        } else {
            temp = rl_rotation(temp);
        }
    }
    return temp;
}

// Insert a new node
avl_node* avlTree::insert(avl_node* root, avl_node* temp) {
    if (root == nullptr) {
        return temp;
    } else if (temp->word < root->word) {
        root->left = insert(root->left, temp);
    } else if (temp->word > root->word) {
        root->right = insert(root->right, temp);
    } else {
        cout << "Duplicate words are not allowed." << endl;
        return root;
    }

    return balance(root);
}

// Driver function for insertion
void avlTree::insert() {
    char ch;
    do {
        string word, meaning;
        cout << "Enter word & its meaning: ";
        cin >> word;
        cin.ignore(); // Ignore leftover newline from input
        getline(cin, meaning);

        avl_node* temp = new avl_node(word, meaning);
        root = insert(root, temp);

        cout << "Press 'y' to continue, else press 'n': ";
        cin >> ch;
    } while (ch == 'y');
}

// Display the AVL tree
void avlTree::display(avl_node* ptr, int level) {
    if (ptr != nullptr) {
        display(ptr->right, level + 1);
        cout << endl;

        // Proper indentation for levels
        for (int i = 0; i < level; i++)
            cout << "   ";

        if (ptr == root)
            cout << "Root -> ";
        
        cout << ptr->word << " (" << ptr->meaning << ")";

        display(ptr->left, level + 1);
    }
}

// Wrapper function
void avlTree::display() {
    if (root == nullptr)
        cout << "Tree is empty!" << endl;
    else {
        cout << "\nAVL Tree Structure:\n";
        display(root, 0);
        cout << "\n";
    }
}

// Main function
int main() {
    cout << "AVL Trees Implementation" << endl;
    avlTree AVLT;
    AVLT.insert();
    cout << "\nAVL Tree Display:" << endl;
    AVLT.display();
    return 0;
}
