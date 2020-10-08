#include <bits/stdc++.h>

using namespace std;


/*
TIME
Worst-case performance	O(n log n)
Best-case performance	O(n log n) typical, O(n) natural variant
Average performance	O(n log n)

SPACE
Worst-case space complexity	О(n) total with O(n) auxiliary, O(1) auxiliary with linked lists

OTHER
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation, it means requires extra space.
Stable: Yes
*/


void printArr(int arr[], int arrSize){
    cout << "Array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int mid, int r){
    int sizeArr1 = mid - l + 1;
    int sizeArr2 = r - mid;
    int arr1[sizeArr1];
    int arr2[sizeArr2];

    for(int i = l, j = 0; i <= mid; i++, j++){
        arr1[j] = arr[i];
    }

    for(int i = mid + 1, j = 0; i <= r; i++, j++){
        arr2[j] = arr[i];
    }

    int arr1It = 0;
    int arr12It = 0;
    while(arr1It < sizeArr1 && arr12It < sizeArr2){
        if(arr1[arr1It] < arr2[arr12It]){
            arr[l++] = arr1[arr1It++];
        }else{
            arr[l++] = arr2[arr12It++];
        }
    }

    while(arr1It < sizeArr1){
        arr[l++] = arr1[arr1It++];
    }

    while(arr12It < sizeArr2){
        arr[l++] = arr2[arr12It++];
    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (r + l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main(){

    int arr[] = {12, 11, 13, 5, 6, 7};

    int n = sizeof(arr) / sizeof(int);
    cout << "n = " << n << endl;

    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
    printArr(arr, n);
    cout << endl;

    return 0;
}
