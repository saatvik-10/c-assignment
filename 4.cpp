// #include<iostream>
// #include<cstdio>
// using namespace std;

// class avl_node {
//     string key;
//     string meaning;
//     avl_node* left;
//     avl_node* right;
// public:
//     friend class avlTree;
// };

// class avlTree {
// public:
//     avl_node *root;
   
//     int height(avl_node*);
//     int diff(avl_node*);
//     avl_node* rr_rotation(avl_node*);
//     avl_node* ll_rotation(avl_node*);
//     avl_node* lr_rotation(avl_node*);
//     avl_node* rl_rotation(avl_node*);
//     avl_node* balance(avl_node*);
//     avl_node* insert(avl_node*, string, string);
//     void display(avl_node*, int);
//     void inorder(avl_node*);
//     void preorder(avl_node*);
//     void postorder(avl_node*);
   
//     avlTree() {
//         root = NULL;
//     }
   
// };

// int avlTree::height(avl_node* temp) {
//     int h = 0;
//     if(temp != NULL) {
//         int l_height = height(temp->left);
//         int r_height = height(temp->right);
//         int max_height = max(l_height,r_height);
//         h = max_height+1;
//     }
//     return h;
// }


// int avlTree::diff(avl_node* temp) {
//     return height(temp->left) - height(temp->right);
// }

// avl_node* avlTree::rr_rotation(avl_node* parent) {
//     avl_node* temp = parent->right;
//     parent->right = temp->left;
//     temp->left = parent;
//     return temp;
// }

// avl_node* avlTree::ll_rotation(avl_node* parent) {
//     avl_node* temp = parent->left;
//     parent->left = temp->right;
//     temp->right = parent;
//     return temp;
// }

// avl_node* avlTree::lr_rotation(avl_node* parent) {
//     parent->left = rr_rotation(parent->left);
//     return ll_rotation(parent);
// }

// avl_node* avlTree::rl_rotation(avl_node* parent) {
//     parent->right = ll_rotation(parent->right);
//     return rr_rotation(parent);
// }

// avl_node* avlTree::balance(avl_node* temp) {
//     int bal_factor = diff(temp);
//     cout << "Balancing node with key " << temp->key << " (Balance Factor = " << bal_factor << ")\n";
//     if (bal_factor > 1) {
//         if (diff(temp->left) >= 0) {
//             cout << "Applying LL Rotation\n";
//             return ll_rotation(temp);
//         } else {
//             cout << "Applying LR Rotation\n";
//             return lr_rotation(temp);
//         }
//     } else if (bal_factor < -1) {
//         if (diff(temp->right) <= 0) {
//             cout << "Applying RR Rotation\n";
//             return rr_rotation(temp);
//         } else {
//             cout << "Applying RL Rotation\n";
//             return rl_rotation(temp);
//         }
//     }
//     return temp;
// }

// avl_node* avlTree::insert(avl_node* node, string key, string meaning) {
//     if (node == NULL) {
//         node = new avl_node;
//         node->key = key;
//         node->meaning = meaning;
//         node->left = NULL;
//         node->right = NULL;
//         return node;
//     }
//     if (key < node->key)
//         node->left = insert(node->left, key, meaning);
//     else
//         node->right = insert(node->right, key, meaning);
//     return balance(node);
// }

// void avlTree::display(avl_node* ptr, int level) {
//     if (ptr != NULL) {
//         display(ptr->right, level + 1);
//         cout << "\n";
//         if (ptr == root)
//             cout << "Root -> ";
//         for (int i = 0; i < level && ptr != root; i++)
//             cout << "                ";
//         cout << ptr->key << ": " << ptr->meaning << " (BF=" << diff(ptr) << ")";
//         display(ptr->left, level + 1);
//     }
// }

// void avlTree::inorder(avl_node* tree) {
//     if (tree == NULL) return;
//     inorder(tree->left);
//     cout << tree->key << ": " << tree->meaning << " ";
//     inorder(tree->right);
// }

// void avlTree::preorder(avl_node* tree) {
//     if (tree == NULL) return;
//     cout << tree->key << ": " << tree->meaning << " ";
//     preorder(tree->left);
//     preorder(tree->right);
// }

// void avlTree::postorder(avl_node* tree) {
//     if (tree == NULL) return;
//     postorder(tree->left);
//     postorder(tree->right);
//     cout << tree->key << ": " << tree->meaning << " ";
// }

// int main() {
//     avlTree tree;
//     int choice;
//     string key, meaning;

//     while (true) {
//         cout << "\nAVL Tree Operations Menu:\n";
//         cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n";
//         cout << "4. Postorder Traversal\n5. Display Tree Structure\n6. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter key to insert: ";
//                 cin >> key;
//                 cout << "Enter meaning: ";
//                 cin.ignore();
//                 getline(cin, meaning);
//                 tree.root = tree.insert(tree.root, key, meaning);
//                 break;
//             case 2:
//                 cout << "Inorder Traversal: ";
//                 tree.inorder(tree.root);
//                 cout << endl;
//                 break;
//             case 3:
//                 cout << "Preorder Traversal: ";
//                 tree.preorder(tree.root);
//                 cout << endl;
//                 break;
//             case 4:
//                 cout << "Postorder Traversal: ";
//                 tree.postorder(tree.root);
//                 cout << endl;
//                 break;
//             case 5:
//                 cout << "Tree Structure:\n";
//                 tree.display(tree.root, 0);
//                 cout << endl;
//                 break;
//             case 6:
//                 cout << "Exiting program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root = nullptr; // Initialize directly without constructor

    int height(Node *node) {
        return node ? node->height : 0;
    }

    int getBalance(Node *node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node *llrotation(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *rrRotation(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *insert(Node *node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // LL
        if (balance > 1 && key < node->left->key)
            return llrotation(node);

        // RR
        if (balance < -1 && key > node->right->key)
            return rrRotation(node);

        // LR
        if (balance > 1 && key > node->left->key) {
            node->left = rrRotation(node->left);
            return llrotation(node);
        }

        // RL
        if (balance < -1 && key < node->right->key) {
            node->right = llrotation(node->right);
            return rrRotation(node);
        }

        return node;
    }

    void preOrder(Node *node) {
        if (node != nullptr) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

public:
    void insert(int key) {
        root = insert(root, key);
    }

    void preOrder() {
        preOrder(root);
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal of constructed AVL tree is:\n";
    tree.preOrder();
    cout << endl;

    return 0;
}
