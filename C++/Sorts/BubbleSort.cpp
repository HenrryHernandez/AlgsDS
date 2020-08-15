#include <bits/stdc++.h>

using namespace std;

/*
How it works? It basically traverses all the array starting from the beginning and, everytime, it
compares with the value at the next position and if they're in wrong order they're swapped and then,
or if not, it continues doing the same with the next one and so on and so forth until it reaches the
final of the array. It does the exact thing for N times, where N is the number of elements on the array.

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

//------------------For Vectors--------------------
void sortVec(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size() - 1; j++){
        //for (int j = 0; j < vec.size()-i-1; j++){ //Doing it like this is a bit more "efficient" but at the end it's still O(n*n)
            if(vec[j] > vec[j + 1]){
                swapThem(vec[j], vec[j + 1]);
            }
        }
    }
}

//to make it more efficient, from O(n*n) to O(n) in case they're already sorted we could do it as follows
void sortVec2(vector<int> &vec){
    bool ordered;
    for(int i = 0; i < vec.size(); i++){
        ordered = true;
        for(int j = 0; j < vec.size() - 1; j++){
        //for (int j = 0; j < vec.size()-i-1; j++){ //Doing it like this is a bit more "efficient" but at the end it's still O(n*n)
            if(vec[j] > vec[j + 1]){
                swapThem(vec[j], vec[j + 1]);
                ordered = false;
            }
        }
        if(ordered)
            break;
    }
}

void printVec(vector<int> vec){
    cout << "Vector: ";
    for(int v : vec)
        cout << v << " ";
    cout << endl;
}

//-------------------------For Arrays---------------------------
void sortArr(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize - 1; j++){
        //for (int j = 0; j < arrSize-i-1; j++){ //Doing it like this is a bit more "efficient" but at the end it's still O(n*n)
            if(arr[j] > arr[j + 1]){
                swapThem(arr[j], arr[j + 1]);
            }
        }
    }
}

//to make it more efficient, from O(n*n) to O(n) in case they're already sorted we could do it as follows
void sortArr2(int arr[], int arrSize){
    bool ordered;
    for(int i = 0; i < arrSize; i++){
        ordered = true;
        for(int j = 0; j < arrSize - 1; j++){
        //for (int j = 0; j < arrSize-i-1; j++){ //Doing it like this is a bit more "efficient" but at the end it's still O(n*n)
            if(arr[j] > arr[j + 1]){
                swapThem(arr[j], arr[j + 1]);
                ordered = false;
            }
        }
        if(ordered)
            break;
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
    sortVec2(vec);
    printVec(vec);

    printArr(arr, 7);
    sortArr2(arr, 7);
    printArr(arr, 7);

    return 0;
}
