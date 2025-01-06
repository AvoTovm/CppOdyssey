#include <iostream>
#include <vector>

using namespace std;

class HeapTree{
    private:
        vector<int> heap;
    public:
        void insert(int key);
        int extractGivenValue(int data);

        void getMax();
        void printHeap();
};

void HeapTree::insert(int key){
    heap.push_back(key);
    int index = heap.size() - 1;

    while(index > 0 && heap[(index - 1) / 2] < heap[index]){
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}

int HeapTree::extractGivenValue(int value) {
    int size = heap.size();
    if(size == 0){
        cout<<"Heap is empty\n";
        return -1;
    }

    int index = -1;
    for(int i = 0; i < size; ++i){
        if(heap[i] == value){
            index = i;
            break;
        }
    }

    if(index == -1){
        cout<<"Value not found in heap\n";
        return -1;
    }

    heap[index] = heap.back();
    heap.pop_back();

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    size = heap.size();

    while(true){
        if(left < size && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < size && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != index){
            swap(heap[index], heap[largest]);
            index = largest;
            left = 2 * index + 1;
            right = 2 * index + 2;
        }else{
            break;
        }
    }

    return value; 
}

void HeapTree::getMax() {
    if (heap.empty()) {
        cout<<"Heap is empty\n";
        return;
    }

    cout<<"Max Element "<<heap[0]<<"\n";
    return;
}

void HeapTree::printHeap() {
    for (const auto &node : heap) {
        cout<<node<<" ";
    }
    cout << endl;
}

int main() {
    HeapTree heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(15);
    heap.insert(30);

    heap.printHeap();
    heap.getMax();

    cout<<"Extracted "<<heap.extractGivenValue(30)<<"\n";

    heap.getMax();

    heap.printHeap();
}
