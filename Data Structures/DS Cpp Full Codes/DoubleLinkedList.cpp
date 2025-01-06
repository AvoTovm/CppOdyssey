#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int value) : data(value), next(nullptr) , prev(nullptr){}
};

class DoubleLinkedList{
    Node* head;
    Node* tail;
    public:
        DoubleLinkedList() : head(nullptr), tail(nullptr){}

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

void DoubleLinkedList::forwardTraversal(){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void DoubleLinkedList::backwardTraversal(){
    Node* temp = tail;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<"\n";
}

bool DoubleLinkedList::searchLinkedList(int target){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int DoubleLinkedList::findLength(){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}

void DoubleLinkedList::insertAtBegin(int value){
    Node* newNode = new Node(value);
    if(!head){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoubleLinkedList::insertAtEnd(int value){
    Node* newNode = new Node(value);
    if(!tail){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoubleLinkedList::insertAtPosition(int pos, int value){
    if(pos < 1){
        cout<<"Invalid Position\n";
        return;
    }
    if(pos == 1){
        insertAtBegin(value);
        return;
    }
    
    Node* newNode = new Node(value);
    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != nullptr; i++){
        temp = temp->next;
    }

    if(!temp){
        cout<<"position out of bounds\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next){
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    if(temp == tail){
        tail = newNode;
    }
}

void DoubleLinkedList::removeAtBegin(){
    if(!head){
        cout<<"list is empty\n";
        return;
    }

    Node* temp = head;
    if(head == tail){
        head = tail = nullptr;
    }else{
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;

}

void DoubleLinkedList::removeAtEnd(){
    if(!tail){
        cout<<"list is empty\n";
        return;
    }

    Node* temp = tail;
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;

}

void DoubleLinkedList::deleteAtPosition(int pos){
    if(pos <= 0){
        cout<<"Invalid position or list is empty\n";
        return;
    }
    if(pos == 1){
        removeAtBegin();
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != nullptr; i++){
        temp = temp->next;
    }

    if(!temp){
        cout<<"position out of bounds\n";
        return;
    }

    if(temp->next){
        temp->next->prev = temp->prev;
    }

    if(temp->prev){
        temp->prev->next = temp->next;
    }

    if(temp == tail){
        tail = temp->prev;
    }
    delete temp;
}

int main(){
    DoubleLinkedList list1;

    list1.insertAtBegin(1);
    list1.insertAtEnd(3);
    list1.insertAtPosition(2,2);

    list1.forwardTraversal();
    list1.backwardTraversal();

    list1.removeAtBegin();
    list1.deleteAtPosition(1);

    list1.forwardTraversal();
}