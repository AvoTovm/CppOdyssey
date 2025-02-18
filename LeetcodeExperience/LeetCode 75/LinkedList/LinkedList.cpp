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

        void reverseList();      //Leetcode 206
        int pairSum();           //Leetcode 2130
        void deleteMiddleNode(); //LeetCode 2095
        void oddEvenList();      //LeetCode 328

};
//odd Even by index not value
void Linkedlist::oddEvenList(){
    if(head == nullptr) return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even != nullptr && even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

}

//Removing midle by length 
void Linkedlist::deleteMiddleNode(){
    int n = findLength();

    if(n <= 0){
        cout<<"invalid position\n";
        return;
    }

    if(n == 1){
        removeFirstNode();
        return;
    }

    Node* curr = head;
    for(int i = 1; i < n / 2; i++){
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

//breaking in half the list
int Linkedlist::pairSum(){
    int n = findLength();
    if(n % 2 != 0){
        cout<<"List is not even\n";
        return -1;
    }
    if(n == 0){
        cout<<"list is empty\n";
        return -1;
    }
    Node* current = head;
    Node* prev = nullptr;
    Node* temp = nullptr;
    int count = 0;

    while(count < n / 2){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }

    Node* firstHalf = prev;
    Node* secondHalf = current;
    int maxSum = 0;

    while(firstHalf != nullptr && secondHalf != nullptr){
        maxSum = max(maxSum, firstHalf->data + secondHalf->data);
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return maxSum;
}

//reverse linked list 
void Linkedlist::reverseList(){ 
    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr){
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
}

void Linkedlist::traverseLinkedList(){
    Node* current = head;

        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }

        cout<<"\n";
}

bool Linkedlist::searchLinkedList(int target){
    while(head != nullptr){
        if(head->data == target){
            return true;
        }
        head = head->next;
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
    list1.insertAtBeginning(1);
    list1.insertAtEnd(4);
    list1.insertPos(2,12);

    //Odd Even Index
    //-------------------------------------------------------------------------------------
    // list1.traverseLinkedList();
    // list1.oddEvenList();
    // list1.traverseLinkedList();
    //-------------------------------------------------------------------------------------

    //Remove Middle
    //-------------------------------------------------------------------------------------
    // list1.traverseLinkedList();
    // list1.deleteMiddleNode();
    // list1.traverseLinkedList();
    //-------------------------------------------------------------------------------------

    //Pair Sum (it breaks list)
    //-------------------------------------------------------------------------------------
    // list1.traverseLinkedList();
    // int result = list1.pairSum();
    // cout<<"max pair = "<<result<<endl;
    //-------------------------------------------------------------------------------------

    //Reversed LinkedList 
    //-------------------------------------------------------------------------------------
    // list1.traverseLinkedList();
    // cout<<"reversed\n";
    // list1.reverseList();
    // list1.traverseLinkedList();
    //-------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------
    // list1.traverseLinkedList();
    // cout<<list1.findLength()<<endl;

    // list1.removeFirstNode();
    // list1.deleteAtPosition(2);

    // list1.traverseLinkedList();

    // list1.removeLastNode();

    // list1.traverseLinkedList();
}
