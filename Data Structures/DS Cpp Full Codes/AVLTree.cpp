#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree{
    public:
        Node* root;

        AVLTree() : root(nullptr) {}

        void insert(int key){
            root = insert(root, key);
        }
        void deleteKey(int key){
            root = deleteNode(root, key);
        }
        bool search(int key){
            return search(root, key);
        }
        void inOrder(){
            inOrder(root);
            cout<<"\n";
        }

    private:
        int getHeight(Node* node);
        int getBalanceFactor(Node* node);
        
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        Node* insert(Node* node, int key);
        Node* minValueNode(Node* node);
        Node* deleteNode(Node* root, int key);

        bool search(Node* root, int key);
        void inOrder(Node* root);
};

int AVLTree::getHeight(Node* node){
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(Node* node){
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* AVLTree::rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* AVLTree::leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, int key){
    if(!node) return new Node(key);

    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node->right, key);
    }else{
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if(balance > 1 && key < node->left->key) return rightRotate(node);
    if(balance < -1 && key > node->right->key) return leftRotate(node);
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVLTree::minValueNode(Node* node){
    Node* current = node;
    while(current->left) current = current->left;
    return current;
}

Node* AVLTree::deleteNode(Node* root, int key){
    if(!root) return root;

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }else{
        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp){
                temp = root;
                root = nullptr;
            }else{
                *root = *temp;
            }
            delete temp;
        }else{
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if(balance > 1 && getBalanceFactor(root->left) >= 0) return rightRotate(root);
    if(balance > 1 && getBalanceFactor(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getBalanceFactor(root->right) <= 0) return leftRotate(root);
    if(balance < -1 && getBalanceFactor(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool AVLTree::search(Node* root, int key){
    if(!root) return false;
    
    if(root->key == key) return root;

    if(key < root->key) return search(root->left, key);
    return search(root->right, key);
}

void AVLTree::inOrder(Node* root){
    if(root){
        inOrder(root->left);
        cout<<root->key<<" ";
        inOrder(root->right);
    }
}

int main(){
    AVLTree tree;

    tree.insert(50);
    tree.insert(40);
    tree.insert(30);


    cout<<"Inorder traversal ";
    tree.inOrder();

    tree.deleteKey(30);
    cout<<"After deleting 30, inorder traversal ";
    tree.inOrder();

    int key = 40;
    cout<<"Search "<<key<<" "<<(tree.search(key) ? "Found\n" : "Not Found\n");
}