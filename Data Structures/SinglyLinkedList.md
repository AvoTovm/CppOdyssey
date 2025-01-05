# Singly Linked List Implementation 

## The implementation includes two classes:

### 1. **__Node Class__**

The Node class represents a single element in the linked list. Each node contains:

+ **data ->** Stores the value of the node.

+ **next ->** A pointer to the next node in the list (or nullptr for the last node).

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

```cpp
void Linkedlist::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
```
### Insert at End

Adds a new node at the end of the list.

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

