#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
};

class Linkedlist {
    private:
        Node *head;

    public:
        Linkedlist(){
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

void Linkedlist::traverseLinkedList(){
    Node* current = head;

    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }

    cout<<"\n";
}

bool Linkedlist::searchLinkedList(int target){
    Node* curr = head;

    while(curr != nullptr){
        if(curr->data == target){
            return true;
        }
        curr = curr->next;
    }

    return false;
}

int Linkedlist::findLength(){
    int lenght = 0;
    Node* current = head;

    while(current != nullptr){
        lenght++;
        current = current->next;
    }

    return lenght;
}

void Linkedlist::insertAtBeginning(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void Linkedlist::insertAtEnd(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = newNode;
}

void Linkedlist::insertPos(int pos, int value){
    if(pos < 1){
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1){
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* curr = head;

    for(int i = 1; i < pos - 1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr){
        cout<<"position out of filed\n";
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void Linkedlist::removeFirstNode(){
    if(head == nullptr){
        cout<<"list is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

void Linkedlist::removeLastNode(){
    if(head == nullptr){
        cout<<"list is empty\n";
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    while(curr->next->next != nullptr){
        curr = curr->next; 
    }

    delete curr->next;
    curr->next = nullptr;
}

void Linkedlist::deleteAtPosition(int position){
    if(position <= 0){
        cout<<"invalid position\n";
        return;
    }

    if(position == 1){
        removeFirstNode();
        return;
    }

    Node* curr = head;
    for(int i = 1; i < position - 1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr || curr->next == nullptr){
        cout<<"Position out of bounds\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

int main(){
    Linkedlist list1;

    list1.insertAtBeginning(3);
    list1.insertAtBeginning(2);
    list1.insertAtEnd(4);
    list1.insertPos(2,12);
    list1.insertPos(2,13);

    list1.traverseLinkedList();
    cout<<list1.findLength()<<endl;

    list1.removeFirstNode();
    list1.deleteAtPosition(2);

    list1.traverseLinkedList();

    list1.removeLastNode();

    list1.traverseLinkedList();
}
