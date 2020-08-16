#include <bits/stdc++.h>
using namespace std;

bool findNumber(vector<int> arr, int x){

    int l = 0;
    int r = arr.size() - 1;
    int mid = 0;

    int c = 0;
    while(l <= r){
        mid = l + ((r - l)  / 2);
        if(x == arr[mid]){
            return true;
        }else if(x > arr[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return false;

}

bool findNumberRecursive(vector<int> arr, int x, int l, int r){
    if(l > r){
        return false;
    }

    int mid = l + ((r - l)  / 2);
    if(x == arr[mid]){
        return true;
    }
    else if(x > arr[mid]){
        return findNumberRecursive(arr, x, mid + 1, r);
    }else{
        return findNumberRecursive(arr, x, l, mid - 1);
    }
}

int main(){
    vector<int> arr;
    for(int i = 0; i < 16; i++){
        arr.push_back(i + 1);
    }

    int x = 16;
    bool b = findNumber(arr, x);
    bool bb = findNumberRecursive(arr, x, 0, arr.size());

    if(bb)
        cout << "found" << endl;
    else
        cout << "fail" << endl;

    return 0;
}
