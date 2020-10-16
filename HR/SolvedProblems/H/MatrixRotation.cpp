#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout << v[i][j];
            if(j + 1 != v[0].size())
            cout << " ";
        }
        if(i + 1 != v.size())
        cout << "\n";
    }
}

void matrixRotation(vector<vector<int>> &matrix, int lo, int hi, int l, int r, int turn) {
    int sizeArr = (r - l) * 2 + (hi - lo) * 2;
    int arr[sizeArr];
    int* arrWithRealValues[sizeArr];

    int c = 0;
    for(int i = lo; i <= hi; i++){
        arrWithRealValues[c] = &matrix[i][l];
        arr[c++] = matrix[i][l];
    }
    for(int i = l + 1; i <= r; i++){
        arrWithRealValues[c] = &matrix[hi][i];
        arr[c++] = matrix[hi][i];
    }
    for(int i = hi - 1; i >= lo; i--){
        arrWithRealValues[c] = &matrix[i][r];
        arr[c++] = matrix[i][r];
    }
    for(int i = r - 1; i > l; i--){
        arrWithRealValues[c] = &matrix[lo][i];
        arr[c++] = matrix[lo][i];
    }

    c = 0;
    while(turn < sizeArr){
        *arrWithRealValues[turn++] = arr[c++];
    }

    turn = 0;
    while(c < sizeArr){
        *arrWithRealValues[turn++] = arr[c++];
    }
}

int main(){
    freopen("input09.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, r;
    cin >> m >> n >> r;

    vector<vector<int>> v(m);
    for(int i = 0; i < v.size(); i++){
        vector<int> v2(n);
        int x;
        for(int j = 0; j < v2.size(); j++){
            cin >> x;
            v2[j] = x;
        }
        v[i] = v2;
    }

    int left = 0, right = n - 1;
    int low = 0, high = m - 1;
    int turns;
    while(right >= left && high >= low){
        turns = r % ((high - low) * 2 + (right - left) * 2);
        matrixRotation(v, low++, high--, left++, right--, turns);
    }

    printMatrix(v);

    return 0;

}
