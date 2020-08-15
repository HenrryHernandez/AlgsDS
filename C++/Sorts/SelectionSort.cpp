#include <bits/stdc++.h>

using namespace std;

/*

How it works? It traverses the whole array looking for the smallest value, starting form the beginning, once 
it finds it, it swaps it for the value at first position; now we'll have the smalles value at the beginning. Then 
it does the same thing, but with the second place to find, now this time, the second smallest, so we start now at 
the second position and do exactly the same. And so on and so forth until it is sorted.


Time Complexity: O(n2) as there are two nested loops.

Auxiliary Space: O(1)

In Place : Yes, it does not require extra space.
*/




/*Found the way of swapping very intresting so I kept it,
but it was not how I did it; mine's commented.*/

void swapBoth(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//For vectors
vector<int> sortItVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        int smallest = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[j] < vec[smallest]){
                smallest = j;
            }
        }
        /*int temp = vec[smallest];
        vec[smallest] = vec[i];
        vec[i] = temp;*/
        swapBoth(&vec[smallest], &vec[i]);
    }

    return vec;

}

void printItVec(vector<int> vec){
    cout << "Vector: ";
    for(int v : vec)
        cout << v << " ";
    cout << endl;
}

//For arrays
void sortItArr(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        int smallest = i;
        for(int j = i + 1; j < arrSize; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        /*int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;*/
        swapBoth(&arr[smallest], &arr[i]);
    }


}

void printItArr(int arr[], int arrSize){
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

    printItVec(vec);
    vec = sortItVec(vec);
    printItVec(vec);

    printItArr(arr, 7);
    sortItArr(arr, 7);
    printItArr(arr, 7);


    return 0;
}
