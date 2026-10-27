//Templated most of the "int" return types and pointer types and added cosnt to getSize for functionality
#include <iostream>
#include <iomanip>

//Had to add these because the Original code provided in canvas needed these but didnt include them(i got compilation errors)
#include <cmath>
#include <algorithm>

using namespace std;

template <typename T>
class MaxHeap {
private:
    T* heap;  //an array
    int capacity;  //maximum number of elements
    int size;  //current number of elements on the heap

    void heapifyUp(int index);

    void heapifyDown(int index);
public:

    MaxHeap(int capacity);
    ~MaxHeap();

    void insert(T value);

    void removeMax();

    T getMax() const;

    void printHeap() const;

    void printHeapTree() const;

    void buildHeapFromArray(T* arr, int n);

    void heapSort();

    int getSize() const;

    const T* getHeap() const;
};

//==================IMPLEMENTATION=================================

//constructor and destructor
//@param  capacity   the maximum number of nodes in the heap
template <typename T>
MaxHeap<T>::MaxHeap(int capacity) {
    this->capacity = capacity;
    
    heap = new T[capacity];
    size = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    cout << "calling delete on internal heap....\n";
    delete[] heap;
}


//=================private helper methods===========
//heapifyUp() used when inserting into the heap
//@param  index   the position to start moving up the tree
template <typename T>
void MaxHeap<T>::heapifyUp(int index) {
    bool keepGoing = true;

    while (keepGoing && index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            keepGoing = false;
        }
    }
}//end heapifyUp()


//heapifyDown() used when deleting from the heap
//@param   index   position to start moving down the heap
template <typename T>
void MaxHeap<T>::heapifyDown(int index) {
    bool keepGoing = true;

    while (keepGoing && 2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;


        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
            keepGoing = false;
    }
}//end heapifyDown()

//=================================================================



//insert into the heap - inserts at last available index, calls heapifyUp()
//@param  value   the value to insert into the heap
template <typename T>
void MaxHeap<T>::insert(T value) {
    if (size == capacity) {
        cout << "Heap is full!" << endl;
        
    }
    else {
        cout << "inserting " << value << endl;
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
}//end insert()



//in a maxheap, the largest is always at root
//move last element into root position and heapifyDown()
template <typename T>
void MaxHeap<T>::removeMax() {
    if (size == 0)
        throw runtime_error("Heap is empty");
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}//end removeMax()



//returns root element, which is guaranteed to be maximum
template <typename T>
T MaxHeap<T>::getMax() const {
    if (size == 0)
        throw runtime_error("Heap is empty");
    return heap[0];
}//end getMax()



//displays in list form
template <typename T>
void MaxHeap<T>::printHeap() const {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}//end printHeap()



//prints heap in tree form
//chatGPT helped with spacing
template <typename T>
void MaxHeap<T>::printHeapTree() const {
    int level = 0;
    int index = 0;

    while (index < size) {
        int nodesInLevel = pow(2, level);
        int spaceBetween = pow(2, max(0, 4 - level)); // adjust for pretty spacing

        // Print spaces before the first number in the level
        cout << setw(spaceBetween);

        for (int i = 0; i < nodesInLevel && index < size; ++i) {
            cout << heap[index++] << setw(spaceBetween * 2);
        }

        cout << endl << endl;
        level++;
    }
}//end printHeapTree()


//builds heap from existing array
//@param  arr   a reference to an existing array
//@param  n     the number of elements in the array
template <typename T>
void MaxHeap<T>::buildHeapFromArray(T* arr, int n) {
    if (n > capacity) {
        cout << "Array is too big to fit in the heap." << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        heap[i] = arr[i];
    }
    size = n;
    for (int i = size / 2 - 1; i >= 0; i--) { //last non-leaf node up to root
        heapifyDown(i);
    }
}//end buildHeapFromArray()




//performs in-place sort on the heap
//intended for use with existing array
template <typename T>
void MaxHeap<T>::heapSort() {
    
    int originalSize = size;

    for (int end = size - 1; end >= 0; end--) {
        swap(heap[0], heap[end]);     // move max to the end
        size--;
        heapifyDown(0);          // restore heap property in reduced heap
    }

    size = originalSize;

    
}//end heapSort()



//Returns the number of elements on the heap
//@return  the number of elements on the heap
template <typename T>
int MaxHeap<T>::getSize() const{
    return size;
}//end getSize()


//returns a pointer to the heap providing read-only access to the heap
//@return const int*   returns the pointer to the heap
template <typename T>
const T* MaxHeap<T>::getHeap() const{
    return heap;
}//end getHeap()
