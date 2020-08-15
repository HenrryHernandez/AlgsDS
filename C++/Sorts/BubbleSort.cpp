#include <bits/stdc++.h>

using namespace std;

/*
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes
*/

void swapThem(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//For Vectors
void sortVec(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size() - 1; j++){
            if(vec[j] > vec[j + 1]){
                swapThem(vec[j], vec[j + 1]);
            }
        }
    }
}

void printVec(vector<int> vec){
    cout << "Vector: ";
    for(int v : vec)
        cout << v << " ";
    cout << endl;
}

//For Arrays
void sortArr(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize - 1; j++){
            if(arr[j] > arr[j + 1]){
                swapThem(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArr(int arr[], int arrSize){
    cout << "Array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    vector<int> vec;
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(1);

    int arr[7];
    arr[0] = 2;
    arr[1] = 8;
    arr[2] = 5;
    arr[3] = 3;
    arr[4] = 9;
    arr[5] = 4;
    arr[6] = 1;

    printVec(vec);
    sortVec(vec);
    printVec(vec);

    printArr(arr, 7);
    sortArr(arr, 7);
    printArr(arr, 7);

    return 0;
}
