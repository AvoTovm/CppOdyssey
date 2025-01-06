#include<iostream>
#include<queue>
#include<stack>
#include<limits>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int value;

    TreeNode(int val) : value(val), right(nullptr), left(nullptr) {}
};

class BinarySearchTree{
    private:
        TreeNode* root;

    public:
        BinarySearchTree() : root(nullptr){}

        void levelOrderTraversal();
        void PostOrderTraversal();

        void insert(int data);
        void removeNode(int pos);

        int findMin();
        void binarySearch(int data);

        void height(int data);
        void depth(int data);

        void treeTypeChecker();
};

void BinarySearchTree::treeTypeChecker() {
    if (root == nullptr) {
        cout << "The tree is empty.\n";
        return;
    }

    bool isPerfect = true;
    bool isFull = true;
    bool isComplete = true;
    bool isDegenerate = true;

    queue<TreeNode*> q;
    q.push(root);

    bool foundIncompleteLevel = false;
    int totalNodes = 0;
    int height = 0;
    int nodeCount = 0;

    while(!q.empty()){
        int levelSize = q.size();
        totalNodes += levelSize;

        while(levelSize--){
            TreeNode* current = q.front();
            q.pop();

            nodeCount++;

            // Check for "perfect" and "complete" properties
            if(current->left){
                if(foundIncompleteLevel) isComplete = false;
                q.push(current->left);
            }else{
                foundIncompleteLevel = true;
            }

            if(current->right){
                if (foundIncompleteLevel) isComplete = false;
                q.push(current->right);
            }else{
                foundIncompleteLevel = true;
            }

            // Check for "full" property
            if((current->left == nullptr && current->right != nullptr) ||
                (current->left != nullptr && current->right == nullptr)){
                isFull = false;
            }

            // Check for "degenerate" property
            if(current->left != nullptr && current->right != nullptr){
                isDegenerate = false;
            }
        }
        height++;
    }

    int expectedNodes = (1 << height) - 1;
    isPerfect = (totalNodes == expectedNodes);

    cout << "Tree Type Check Results\n";
    if(isPerfect) cout << " - Perfect Binary Tree\n";
    if(isFull) cout << " - Full Binary Tree\n";
    if(isComplete) cout << " - Complete Binary Tree\n";
    if(isDegenerate) cout << " - Degenerate Binary Tree\n";

    if(!isPerfect && !isFull && !isComplete && !isDegenerate){
        cout << " - None of the above types.\n";
    }
}

void BinarySearchTree::levelOrderTraversal(){
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        cout<<temp->value<<" ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    cout<<"\n";
}

void BinarySearchTree::PostOrderTraversal(){
    if(root == nullptr) return;

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

void BinarySearchTree::insert(int data){
    TreeNode* newNode = new TreeNode(data);

    if(root == nullptr){
        root = newNode;
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while(current != nullptr){
        parent = current;
        if(data < current->value){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(data < parent->value){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
}

int BinarySearchTree::findMin(){
    TreeNode* current = root;

    while(current->left != nullptr){
        current = current->left;
    }

    return current->value;
}

void BinarySearchTree::removeNode(int data){
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while(current != nullptr && current->value != data){
        parent = current;
        if(current->value > data){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(current == nullptr){
        cout<<"Node "<<data<<" not found\n";
        return;
    }

    //case 1 has no children

    if(current->left == nullptr && current->right == nullptr){
        if(current == root){
            root = nullptr;
        }else if(parent->left == current){
            parent->left = nullptr;
        }else{
            parent->right = nullptr;
        }
        delete current;
    }

    //case 2 has one children

    else if(current->left == nullptr || current->right == nullptr){
        TreeNode* child = (current->left != nullptr) ? current->left : current->right;

        if(current == root){
            root = child;
        }else if(parent->left == current){
            parent->left = child;
        }else{
            parent->right = child;
        }

        delete current;
    }

    //case 3 has two children

    else{
        TreeNode* succsessorParent = current;
        TreeNode* succsessor = current->right;

        while(succsessor->left != nullptr){
            succsessorParent = succsessor;
            succsessor = succsessor->left;
        }

        current->value = succsessor->value;

        if(succsessorParent->left == succsessor){
            succsessorParent->left = succsessor->right;
        }else{
            succsessorParent->right = succsessor->right;
        }

        delete succsessor;
    }


}

void BinarySearchTree::binarySearch(int data){
    TreeNode* current = root;

    int steps = 0;

    while(current != nullptr){
        if(current->value == data){
            cout<<"The "<<data<<" found in "<<steps<<" steps \n";
            return;
        }else if(current->value > data){
            current = current->left;
        }else{
            current = current->right;
        }
        steps++;
    }

    cout<<"Not Found\n";
}

void BinarySearchTree::depth(int data) {
    TreeNode* current = root;

    int depth = 0;

    while(current != nullptr){
        if(data == current->value){
            cout<<"Depth of node "<<data<<" is "<<depth<< "\n";
            return;
        }else if(data < current->value){
            current = current->left;
        }else{
            current = current->right;
        }
        depth++;
    }

    cout<<"Node not found "<<data<<"\n";
    return;
}

void BinarySearchTree::height(int data){
    TreeNode* current = root;

    while(current != nullptr && current->value != data){
        if(current->value > data){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(current == nullptr){
        cout<<"Node not found\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(current);

    int height = -1;

    while(!q.empty()){
        int levelSize = q.size();
        height++;

        for(int i = 0; i < levelSize; i++){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    cout<<"Height of node "<<data<<" is "<<height <<"\n";
}

int main(){
    BinarySearchTree tree1;

    tree1.insert(4);
    tree1.insert(2);
    tree1.insert(6);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(5);
    tree1.insert(7);

    tree1.levelOrderTraversal();
    tree1.PostOrderTraversal();
    tree1.removeNode(4);

    tree1.levelOrderTraversal();

    tree1.binarySearch(7);
    tree1.depth(7);
    tree1.height(2);

    tree1.treeTypeChecker();
}