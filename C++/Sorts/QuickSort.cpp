#include <bits/stdc++.h>

using namespace std;

/*
How it works?
First of all, we must pick up a pivot; it cand be done the following way:
-Always pick first element as pivot.
-Always pick last element as pivot (implemented below)
-Pick a random element as pivot.
-Pick median as pivot.
As we said, we're implementing the second method of choosing pivot.
Once we have the pivot, it's about leaving in the left side of the pivot all the elements smaller than
the pivot and all the grater in the right side; they not necesarilly have to be sorted, but
considering the pivot, all smaller values than it must go to the left and the grater to the right.
Then, since the pivot is already in its right place, we'll do the same, but with the left and right
part of the pivot, and since it is a recursive method, it automatically will be doing the same.
And that is it.


Time Complexity for Quicksort
The worst case occurs when the partition process always picks the greatest or smallest item as a pivot
and the complexity of Worst Case: O(N^2), like we did in this case.

The best-case occurs when a partition process always picks the middle element as pivot. And the complexity
of Best Case: O(N).

The average case means when there is neither a balanced tree nor like the Worst Case. The complexity of the
Average Case: (N log N).

Is QuickSort stable?
The default implementation is not stable. However any sorting algorithm can be made stable by considering
indexes as comparison parameter.
Is QuickSort In-place?
As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses
extra space only for storing recursive function calls but not for manipulating the input.
*/

void swapThem(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int arr[], int arrSize){
    cout << "Array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}


//THIS IS TAKING RIGHT MOST NUMBER AS THE PIVOT
int Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {

        if (arr[j] <= pivot)
        {
            swapThem(arr[i], arr[j]);
            i++;
        }
    }
    swapThem(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pivot = Partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}


//THIS IS TAKING LEFT MOST NUMBER AS THE PIVOT
/*int Partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l;
    int j = r;

    while(i < j){
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i < j)
            swapThem(arr[i], arr[j]);
    }
    swapThem(arr[l], arr[j]);

    return j;

}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pivot = Partition(arr, l, r);
        quickSort(arr, l, pivot);
        quickSort(arr, pivot + 1, r);
    }
}*/

int main(){

    int arr[7];
    arr[0] = 2;
    arr[1] = 8;
    arr[2] = 5;
    arr[3] = 3;
    arr[4] = 9;
    arr[5] = 4;
    arr[6] = 1;

    printArr(arr, 7);
    quickSort(arr, 0, 6);
    printArr(arr, 7);
    cout << endl;

    return 0;
}
