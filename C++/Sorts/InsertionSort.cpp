#include <bits/stdc++.h>

using namespace std;

/*

How it works? We start with the second element and compare with its previous, if they are in different order, we
swap them. For the 3th position, we'll do the same, but this time in case there is a swap now it'll be the 2nd one,
so then we will check with the previous again and if the're in different order again, we swap them too. An then with
the 4th one and so on and so forth. If there is not a swap, we stop checking with all the previous ones cuz they'll be
smaller too because everytime we go for a new position to check, all the previous of the previous to it will be smaller.


Time Complexity: O(n*n)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes
minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach

Sorting In Place: Yes

Stable: Yes

Online: Yes
*/


void swapThem(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sortArr(int arr[], int arrSize){

    for(int i = 1; i < arrSize; i++){
         int j = i;
         while(arr[j] < arr[j - 1] && j > 0){
            swapThem(arr[j], arr[j - 1]);
            j--;
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

    int arr[7];
    arr[0] = 2;
    arr[1] = 8;
    arr[2] = 5;
    arr[3] = 3;
    arr[4] = 9;
    arr[5] = 4;
    arr[6] = 1;

    printArr(arr, 7);
    sortArr(arr, 7);
    printArr(arr, 7);

    return 0;
}
