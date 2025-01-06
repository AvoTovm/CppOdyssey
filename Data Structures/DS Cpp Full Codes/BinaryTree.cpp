#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void levelOrderTraversal();

    void insert(int value);
    void deleteValue(int value);
    int findMax();
    int findElement(int data);
    int deepest();

    int maxDepth();

};

void BinaryTree::levelOrderTraversal(){
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        cout<<temp->value<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void BinaryTree::inorderTraversal() {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while(current != nullptr || !s.empty()){

        while(current != nullptr){
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout<<current->value<<" ";

        current = current->right;
    }

    cout<<"\n";
}

void BinaryTree::preorderTraversal() {
    if(root == nullptr){
            return;
        }

    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();

        cout<<temp->value<<" ";
        if(temp->right){
            s.push(temp->right);
        }

        if(temp->left){
            s.push(temp->left);
        }
    }

    cout<<"\n";
}
 
void BinaryTree::postorderTraversal() {
    if(root == nullptr){
        return;
    }

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while(!s1.empty()){
        TreeNode* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }

    while(!s2.empty()){
        cout<<s2.top()->value<<" ";
        s2.pop();
    }

    cout<<"\n";
}

void BinaryTree::insert(int value){
    TreeNode* newNode = new TreeNode(value);
    if(root == nullptr){
        root = newNode;
    }else{
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left == nullptr){
                temp->left = newNode;
                return;
            }else{
                q.push(temp->left);
            }

            if(temp->right == nullptr){
                temp->right = newNode;
                return;
            }else{
                q.push(temp->right);
            }
        }
    }
}

void BinaryTree::deleteValue(int value){
    if(root == nullptr) return;

    TreeNode* nodeToDelete = nullptr;
    TreeNode* temp;
    TreeNode* parent = nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->value == value){
            nodeToDelete = temp;
        }
        if(temp->left){
            parent = temp;
            q.push(temp->left);
        }
        if(temp->right){
            parent = temp;
            q.push(temp->right);
        }
    }

    if(nodeToDelete == nullptr) return;

    nodeToDelete->value = temp->value;

    if(parent->right == temp){
        parent->right = nullptr;
    }else{
        parent->left = nullptr;
    }

    delete temp;
}

int BinaryTree::findMax(){
    if(root == nullptr) return numeric_limits<bool>::min();

    int maxValue = root->value;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp->value > maxValue){
            maxValue = temp->value;
        }

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
    return maxValue;
}


int BinaryTree::findElement(int data){
    if(root == nullptr){
        cout<<"element not found\n";
        return false;  
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->value == data){
            cout<<"element found\n";
            return true;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout<<"element not found\n";
    return false;
}

int BinaryTree::deepest(){
    if(root == nullptr) return -1;

    TreeNode* temp = nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    cout<<"Deepest value is "<<temp->value<<"\n";
    return temp->value;
}

int BinaryTree::maxDepth(){
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while(!q.empty()){
        int levelSize = q.size();

        for(int i = 0; i < levelSize; ++i){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        depth++;
    }

    cout<<depth<<"\n";
    return depth;
}


int main() {
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    //tree.deepest();
    //tree.maxDepth();

    //tree.deleteValue(7);
    //tree.findElement(7);

    cout<<"Inorder Traversal ";
    tree.inorderTraversal();

    cout<<"Preorder Traversal ";
    tree.preorderTraversal();

    cout<<"Postorder Traversal ";
    tree.postorderTraversal();

    cout<<"Levelorder Traversal ";
    tree.levelOrderTraversal();

}
