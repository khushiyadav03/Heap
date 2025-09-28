#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap; 

    // function to move ele up (stepup heapify)
    void heapifyUP(int i ){
        // keep moving till we reach root (index 0)
        while( i > 0 && heap[(i-1) / 2] > heap[i]){
            // if parent < child --> swap
            swap(heap[i], heap[(i-1) / 2]);
             i = (i - 1) / 2;
        }
    }

    // function to move ele down (Stepdown heapify)
    void heapifyDown(int i ) {
        int n = heap.size();

        while(true){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i; // let curr be largest

            // check if left child is bigger
            if(left < n && heap[left] < heap[smallest]){
                smallest = left;
            }

            // check if right child is bigger
            if(right < n && heap[right] < heap[smallest]){
                smallest = right;
            }

            // if parent is already largest -> break
            if(smallest == i){
                break;
            }

            // else swap parent with largest child
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    public :
    
    // insert new value in heap
    void insert(int val){
        heap.push_back(val);
        heapifyUP(heap.size() - 1);
    }

    // delete root ele (max ele in max heap)
    void deleteRoot(){
        if(heap.empty())
            return;

        heap[0] = heap.back(); // move last ele to root
        heap.pop_back(); // remove last ele
        heapifyDown(0); // fix heap property
    }

    //print heap
    void print(){
        for(int x : heap){
            cout << x << " ";
        }

        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Min Heap: ";
    h.print();

    h.deleteRoot();
    cout << "After deleting root: ";
    h.print();
}