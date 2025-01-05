# Binary Tree Implementation

## The implementation includes two classes:

### 1. **__TreeNode Class(Struct)__**

The Node class represents a single element in the Binary Tree. Each node contains:

+ **value ->** Stores the value of the node.

+ **left ->** Pointer to the left child.

+ **right ->** Pointer to the right child.

![image](https://github.com/user-attachments/assets/f7b1b03b-9650-4ac7-8710-7bb730cffc9c)

```cpp
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
```

### 2. **__BinaryTree Class__**

The BinaryTree class manages the nodes and provides various operations. It contains:

+ **root ->** Pointer to the root node of the tree.

```cpp
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
```

## Member Functions

### Traversals

1. Inorder Traversal:

   - Visits the left subtree, root, and then the right subtree.

   - Uses a stack for iterative traversal.

![image](https://github.com/user-attachments/assets/f84745c3-a86b-4d56-98dd-9694472def8a)

```cpp
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
```

2. Preorder Traversal:

   - Visits the root, left subtree, and then the right subtree.

   - Uses a stack for iterative traversal.

![image](https://github.com/user-attachments/assets/38db3a64-67f4-47c6-933c-1b3c6c356e36)

```cpp
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
```

3. Postorder Traversal:

   - Visits the left subtree, right subtree, and then the root.

   - Uses a stack for iterative traversal.

![image](https://github.com/user-attachments/assets/f78805e0-ccb8-4bd4-803e-9b58510f3504)

```cpp
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
```

4. Level Order Traversal:

   - Visits nodes level by level.

   - Uses a queue for traversal.

```cpp
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
```

## Insertion

Inserts a new value at the first available position in level order.

```cpp
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
```

## Deletion

Finds the node to delete and replaces its value with the deepest node's value. The deepest node is then removed.

```cpp
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
```

## Finding Maximum

Traverses the tree in level order and keeps track of the maximum value encountered.

```cpp
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
```

## Finding an Element

Traverses the tree in level order and checks if the value exists.

```cpp
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
```

## Deepest Node

Traverses the tree in level order and returns the value of the last node visited.

```cpp
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
```

## Maximum Depth

Computes the depth by counting levels using a queue in level order traversal.

```cpp
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
```
