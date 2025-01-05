# Singly Linked List Implementation 

## The implementation includes two classes:

### 1. **__Node Class__**

The Node class represents a single element in the linked list. Each node contains:

+ **data ->** Stores the value of the node.

+ **next ->** A pointer to the next node in the list (or nullptr for the last node).

![image](https://github.com/user-attachments/assets/b64c7fa3-1a61-47ce-8b53-b48dedd60042)

```cpp
class Node{
    public:
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
};
```

### 2. **__Linkedlist Class__**

The Linkedlist class manages the nodes and provides various operations. It contains:

+ **head ->** A pointer to the first node in the list.

```cpp
class Linkedlist {
    private:
        Node *head;

    public:
        Linkedlist() {
            head = nullptr;
        }

        void traverseLinkedList();
        bool searchLinkedList(int target);
        int findLength();

        void insertAtBeginning(int value);
        void insertAtEnd(int value);
        void insertPos(int pos, int value);

        void removeFirstNode();
        void removeLastNode();
        void deleteAtPosition(int position);
};
```

## Member Functions

### Traversal
Traverses the linked list and prints the data of each node.

```cpp
void Linkedlist::traverseLinkedList() {
    Node* current = head;

    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}
```

### Search

Searches for a specific value in the linked list and returns true if found.

```cpp
bool Linkedlist::searchLinkedList(int target) {
    Node* curr = head;

    while(curr != nullptr) {
        if(curr->data == target) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}
```

### Find Length

Calculates and returns the number of nodes in the linked list.

```cpp
int Linkedlist::findLength() {
    int length = 0;
    Node* current = head;

    while(current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}
```

## Insertions

### Insert at Beginning

Adds a new node at the beginning of the list.

![image](https://github.com/user-attachments/assets/65936308-2846-45a1-a0f7-34b7828df955)

```cpp
void Linkedlist::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
```
### Insert at End

Adds a new node at the end of the list.

![image](https://github.com/user-attachments/assets/4cfcb7fa-41ba-4a9c-b70c-781b8b0e4214)

```cpp
void Linkedlist::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}
```
### Insert at Position

Inserts a new node at a specific position in the list.

![image](https://github.com/user-attachments/assets/bf54e9ac-eb05-4346-ac12-95b24d6f3a3c)

```cpp
void Linkedlist::insertPos(int pos, int value) {
    if(pos < 1) {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* curr = head;

    for(int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if(curr == nullptr) {
        cout << "Position out of bounds\n";
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}
```

## Deletions

### Remove First Node

Deletes the first node in the list.

![image](https://github.com/user-attachments/assets/b94d303e-1533-463f-95b3-2c00d7d2bc1a)

```cpp
void Linkedlist::removeFirstNode() {
    if(head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}
```

### Remove Last Node

Deletes the last node in the list.

```cpp
void Linkedlist::removeLastNode() {
    if(head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    while(curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
}
```

### Delete at Position

Deletes the node at a specific position in the list.

![image](https://github.com/user-attachments/assets/c6b531da-6f75-45fe-ad1e-0ad115f73417)

```cpp
void Linkedlist::deleteAtPosition(int position) {
    if(position <= 0) {
        cout << "Invalid position\n";
        return;
    }

    if(position == 1) {
        removeFirstNode();
        return;
    }

    Node* curr = head;
    for(int i = 1; i < position - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if(curr == nullptr || curr->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}
```

