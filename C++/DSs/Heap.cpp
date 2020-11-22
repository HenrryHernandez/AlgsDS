#include <bits/stdc++.h>

using namespace std;

/*
    Insertion Time Complexity: O(n log n)
    Deletion Time Complexity: O(n log n)
    This is because of the process that we have to follow in case a node is in
    the wrong place after we insert or delete.

    Heapify: Process of converting an array to a heap.
    Heapify Time Complexity: O(n)
    It's better to heapify an array than creating another one cuz it's faster.
*/


class MaxHeap {
    private:
        int n = 20;
        int currentSize = 0;
        vector<int> v;

        bool isFull(){
            if(currentSize >= n) return true;
            return false;
        }

        bool isEmpty(){
            if(currentSize == 0) return true;
            return false;
        }

        int getAtIndex(int index){
            if(index >= currentSize) return INT_MIN;
            return (v[index]);
        }

        void checkAfterInsertion(){
            int tempPos = currentSize;
            while(v[(tempPos - 1) / 2] < v[tempPos]){
                swap(v[(tempPos - 1) / 2], v[tempPos]);
                tempPos = (tempPos - 1) / 2;
            }
        }

        void checkAfterDeletion(){
            int tempIndex = 0;
            while(  v[tempIndex] < getAtIndex(tempIndex * 2 + 1) ||
                    v[tempIndex] < getAtIndex(tempIndex * 2 + 2)){
                if(getAtIndex(tempIndex * 2 + 1) > getAtIndex(tempIndex * 2 + 2)){
                    swap(v[tempIndex], v[tempIndex * 2 + 1]);
                    tempIndex = tempIndex * 2 + 1;
                }else{
                    swap(v[tempIndex], v[tempIndex * 2 + 2]);
                    tempIndex = tempIndex * 2 + 2;
                }
            }
        }

        void heapifyAtIndex(int i){
            int tempIndex = i;
            while(  v[tempIndex] < getAtIndex(tempIndex * 2 + 1) ||
                    v[tempIndex] < getAtIndex(tempIndex * 2 + 2)){
                if(getAtIndex(tempIndex * 2 + 1) > getAtIndex(tempIndex * 2 + 2)){
                    swap(v[tempIndex], v[tempIndex * 2 + 1]);
                    tempIndex = tempIndex * 2 + 1;
                }else{
                    swap(v[tempIndex], v[tempIndex * 2 + 2]);
                    tempIndex = tempIndex * 2 + 2;
                }
            }
        }

    public:
        MaxHeap(){

        }

        MaxHeap(vector<int> v){
            this->v = v;
            this->currentSize = v.size();
        }

        void insertInHeap(int val){
            if(isFull()){
                cout << "Not enough space" << endl;
                return;
            }

            if(v.size() == currentSize) v.push_back(val);
            else v[currentSize] = val;

            checkAfterInsertion();
            currentSize++;
        }

        void deleteFromHeap(){
            if(isEmpty()){
                cout << "Heap empty. Not elements to delete." << endl;
                return;
            }
            swap(v[0], v[currentSize - 1]);
            currentSize--;
            checkAfterDeletion();
        }

        void printTree(){
            if(isEmpty()){
                cout << "Heap empty" << endl;
                return;
            }
            for(int i = 0; i < currentSize; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }

        void printCompleteArray(){
            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
        }

        void heapSort();
        void heapify();

};

//I put it here just to try this syntax
void MaxHeap::heapSort(){
    while(currentSize){
        deleteFromHeap();
    }
    cout << "Heap sorted: ";
    printCompleteArray();
}

//I put it here just to try this syntax
void MaxHeap::heapify(){
    for(int i = currentSize - 1; i >= 0; i--){
        heapifyAtIndex(i);
    }
}



int main(){

    //We can start creating our own
    /*MaxHeap mx;
    mx.printTree();
    mx.insertInHeap(50);
    mx.insertInHeap(30);
    mx.insertInHeap(20);
    mx.insertInHeap(15);
    mx.insertInHeap(10);
    mx.insertInHeap(8);
    mx.insertInHeap(16);
    mx.printTree();
    mx.insertInHeap(60);
    mx.printTree();
    mx.insertInHeap(160);
    mx.printTree();
    mx.heapSort();*/

    /*Or we can pass one array and start operating with it, but if we use this approach, we'd be violating
    the rule that there shouldn't be more than n elements in the heap. One alternative is to truncate
    the array to the specified size (n) and let the user know about it. For now, I'll leave it as it is*/
    vector<int> v = {4, 2, 5, 1, 4, 6, 2, 2, 5, 1, 4, 6, 2, 2, 5, 1, 4, 6, 2, 2, 5, 1, 4, 6, 2, 2, 5, 1, 4, 6, 2};
    MaxHeap mx(v);
    mx.heapify();
    mx.printTree();

    return 0;
}
