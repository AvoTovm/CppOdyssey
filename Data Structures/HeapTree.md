# HeapTree Implementation

![image](https://github.com/user-attachments/assets/e4b2cb3a-718f-4cc9-9a1b-2acd6b09032e)

## HeapTree Class

The HeapTree class uses a vector (heap) to store the elements of the heap. It provides the following functionalities:

+ **insert(int key):** Inserts a new element into the heap while maintaining the heap property.

+ **extractGivenValue(int data):** Removes a specific value from the heap.

+ **getMax():** Retrieves the maximum element from the heap.

+ **printHeap():** Prints all elements of the heap.

```cpp
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
```

## Function Implemetations

### 1.Insert

+ Add the new key at the end of the vector.

+ Check its parent node. If the parent's value is smaller, swap them.

+ Continue this process until the heap property is restored (the parent is larger than the child).

![image](https://github.com/user-attachments/assets/bf2e084b-38cb-44c6-9989-200126244487)

```cpp
void HeapTree::insert(int key){
    heap.push_back(key);
    int index = heap.size() - 1;

    while(index > 0 && heap[(index - 1) / 2] < heap[index]){
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}
```

### 2. Extract Given Value Function

+ Locate the value in the heap. If not found, return an error message.

+ Replace the value with the last element and remove the last element.

+ Restore the heap property by comparing the modified node with its children and swapping if necessary.

+ Continue until the heap property is restored.

```cpp
int HeapTree::extractGivenValue(int value){
    int size = heap.size();
    if(size == 0){
        cout << "Heap is empty\n";
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
        cout << "Value not found in heap\n";
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
        } else {
            break;
        }
    }

    return value;
}
```

### 3. Get Max Function

+ Print the root of the heap, which contains the maximum value.

+ If the heap is empty, display an appropriate message.

```cpp
void HeapTree::getMax(){
    if(heap.empty()){
        cout << "Heap is empty\n";
        return;
    }

    cout<<"Max Element "<<heap[0]<<"\n";
    return;
}
```

### 4. Print Heap Function

+ Iterate through the vector and print all elements of the heap.

```cpp
void HeapTree::printHeap(){
    for(const auto &node : heap){
        cout<<node<<" ";
    }
    cout<<endl;
}
```
