# Class Design
## The implementation includes two main classes:

### 1. Node Class
The Node class represents a single element in the doubly linked list. Each node contains:

+ **__data ->__** Stores the value of the node.
+ **__next ->__** A pointer to the next node in the list.
+ **__prev ->__** A pointer to the previous node in the list.

![image](https://github.com/user-attachments/assets/3165117f-e0e0-4828-8847-0aea729a1285)

```cpp
class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

```

### 2. DoubleLinkedList Class
The DoubleLinkedList class manages the nodes and provides various operations. It contains:

+ **__head ->__** A pointer to the first node in the list.
+ **__tail ->__** A pointer to the last node in the list.

```cpp
class DoubleLinkedList {
    Node* head;
    Node* tail;

    public:
        DoubleLinkedList() : head(nullptr), tail(nullptr) {}

        void forwardTraversal();
        void backwardTraversal();
        bool searchLinkedList(int target);
        int findLength();

        void insertAtBegin(int value);
        void insertAtEnd(int value);
        void insertAtPosition(int pos, int value);

        void removeAtBegin();
        void removeAtEnd();
        void deleteAtPosition(int pos);
};

```

## Member Functions

### Traversals

**Forward Traversal**
Prints the data of each node starting from the head.

```cpp
void DoubleLinkedList::forwardTraversal() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

```

**Backward Traversal**
Prints the data of each node starting from the tail.

```cpp
void DoubleLinkedList::backwardTraversal() {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}
```

### Search
Searches for a specific value in the list and returns true if found.

```cpp
bool DoubleLinkedList::searchLinkedList(int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
```

### Find Length
Counts and returns the number of nodes in the list.

```cpp
int DoubleLinkedList::findLength() {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
```

## Insertions

### Insert at Beginning

Adds a new node at the beginning of the list.

![image](https://github.com/user-attachments/assets/9b0894d1-0f7a-47c5-a318-217827f9f340)

```cpp
void DoubleLinkedList::insertAtBegin(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
```

### Insert at End

Adds a new node at the end of the list.

```cpp
void DoubleLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
```

### Insert at Position

Inserts a new node at a specified position in the list.

![image](https://github.com/user-attachments/assets/3d97b056-7122-479a-bd77-13f6926253e3)

```cpp
void DoubleLinkedList::insertAtPosition(int pos, int value) {
    if (pos < 1) {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1) {
        insertAtBegin(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode;
    }
}
```

## Deletions

### Remove at Beginning

Deletes the first node in the list.

![image](https://github.com/user-attachments/assets/347ffce0-28b0-4c15-98c5-de316c61d25d)

```cpp
void DoubleLinkedList::removeAtBegin() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}
```

### Remove at End

Deletes the last node in the list.

```cpp
void DoubleLinkedList::removeAtEnd() {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}
```

### Delete at Position

Deletes the node at a specified position in the list.

![image](https://github.com/user-attachments/assets/502d5cd4-e005-410d-b8c7-f746ed1b8ce6)

```cpp
void DoubleLinkedList::deleteAtPosition(int pos) {
    if (pos <= 0) {
        cout << "Invalid position or list is empty\n";
        return;
    }

    if (pos == 1) {
        removeAtBegin();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds\n";
        return;
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    }

    if (temp == tail) {
        tail = temp->prev;
    }

    delete temp;
}
```
