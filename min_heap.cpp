#include <iostream>
#include <climits>
using namespace std;

class MinHeap
{
    int *heap;      //pointer to elements of heap
    int size;       //current number of elements in the heap
    int capacity;   //max_size possible for the heap
public:
    MinHeap(int max_size);  //constructor
    // functions to return parent, left child and right child index
    int parent(int x) { return (x-1)/2; }
    int lchild(int x) { return (2*x+1); }
    int rchild(int x) { return (2*x+2); }
    // Heap Functions: minHeapify, getMin, extractMin, decreaseKey, deleteKey, insertKey
    int getMin() { return heap[0]; }
    void minHeapify( int index );
    int extractMin();
    void decreaseKey(int index, int newKey);
    void deleteKey(int index);
    void insertKey(int key);
};

MinHeap::MinHeap(int max_size){
    size = 0; // initialized heap has no elements
    capacity = max_size;
    heap = new int[capacity];
}

void MinHeap::insertKey(int key){
    // check if size = capacity
    if(size == capacity){
        cout<<"Heap is Full"<<endl;
        return;
    }
    // increase size of heap
    size++;
    // insert element at the end
    heap[size-1] = key;
    // if parent of newly inserted element is greater then swap until min-heap property holds
    int currIndex=size-1;
    while(heap[parent(currIndex)] > heap[currIndex] && currIndex > 0){
        heap[parent(currIndex)] = heap[parent(currIndex)] ^ heap[currIndex];
        heap[currIndex] = heap[parent(currIndex)] ^ heap[currIndex];
        heap[parent(currIndex)] = heap[parent(currIndex)] ^ heap[currIndex];
        currIndex = parent(currIndex);
    }
}

void MinHeap::decreaseKey(int index,int newKey){
    heap[index] = newKey;
    while(index!=0 && heap[parent(index)]>heap[index]){
        heap[parent(index)] = heap[parent(index)] ^ heap[index];
        heap[index] = heap[parent(index)] ^ heap[index];
        heap[parent(index)] = heap[parent(index)] ^ heap[index];
        index = parent(index);
    }
}

int MinHeap::extractMin(){
    if(size == 0) return INT_MAX;
    if(size == 1){
        size--;
        return heap[0];
    }
    // store min element
    int min = heap[0];
    // replace top of heap with last element
    heap[0] = heap[size-1];
    // reduce size of heap
    size--;
    // call heapify from top of heap
    minHeapify(0);
    // return extracted min element
    return min;
}

void MinHeap::deleteKey(int index){
    decreaseKey(index,INT_MIN);
    extractMin();
}

void MinHeap::minHeapify(int index){
    // find the smallest element out of index, lChild(index) and rchild(index)
    int left = lchild(index);
    int right = rchild(index);
    int smallest = index;
    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;
    // if index is not the smallest element then swap it with smallest and call minHeapify on it
    if(smallest != index){
        heap[smallest] = heap[smallest] ^ heap[index];
        heap[index] = heap[smallest] ^ heap[index];
        heap[smallest] = heap[smallest] ^ heap[index];
        minHeapify(smallest);
    }
}
// Implementation:
// elements = [5,10,15,20,25]
int main(){
    MinHeap myHeap(10);
    int data[] = {25,20,15,10,5};
    for(int i=0;i<5;i++){
        myHeap.insertKey(data[i]);
    }
    cout<<"Minumum key is: "<<myHeap.getMin()<<endl;
    myHeap.decreaseKey(5,17);
    cout<<"Extracted Key: "<<myHeap.extractMin()<<endl;
    cout<<"Minimum Key is: "<<myHeap.getMin()<<endl;
}
