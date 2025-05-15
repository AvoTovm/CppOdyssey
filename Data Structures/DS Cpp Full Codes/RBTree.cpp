#include <iostream>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val)
        : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node*& root, Node*& x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node*& root, Node*& x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node*& root, Node*& pt) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (pt != root && pt->color == RED && pt->parent->color == RED) {
            parent = pt->parent;
            grandparent = parent->parent;

            // Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    // Case 2: pt is right child
                    if (pt == parent->right) {
                        rotateLeft(root, parent);
                        pt = parent;
                        parent = pt->parent;
                    }

                    // Case 3: pt is left child
                    rotateRight(root, grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            } else {
                // Parent is right child of grandparent
                Node* uncle = grandparent->left;

                // Case 1: Uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    // Case 2: pt is left child
                    if (pt == parent->left) {
                        rotateRight(root, parent);
                        pt = parent;
                        parent = pt->parent;
                    }

                    // Case 3: pt is right child
                    rotateLeft(root, grandparent);
                    std::swap(parent->color, grandparent->color);
                    pt = parent;
                }
            }
        }
        root->color = BLACK;
    }

    void inorderHelper(Node* root) {
        if (root == nullptr)
            return;

        inorderHelper(root->left);
        cout << root->data << " (" << (root->color == RED ? "R" : "B") << ") ";
        inorderHelper(root->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        Node* pt = new Node(data);

        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (pt->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;

        if (parent == nullptr)
            root = pt;
        else if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        fixInsert(root, pt);
    }

    void inorder() {
        inorderHelper(root);
        cout<<"\n";
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    cout<<"Inorder Traversal -> ";
    tree.inorder();
}
