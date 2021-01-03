#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVec(vector<T> &v){
    for(T i : v){
        cout << i << " ";
    }
    cout << endl;
}

int maxHeight(vector<vector<int>>& cuboids) {
    std::sort(cuboids.begin(), cuboids.end(), [] (vector<int> a, vector<int> b){
        int v1 = 1;
        int v2 = 1;

        for(int i : a) v1 *= i;
        for(int i : b) v2 *= i;

        return v1 > v2;
    });

    int tallest = 0;
    for(int i = 0; i < cuboids.size(); i++){
        sort(cuboids[i].begin(), cuboids[i].end());
        for(int j : cuboids[i]){
            if(j > tallest) tallest = j;
        }
    }

    for(vector<int> v : cuboids){
        printVec(v);
	}

    int maxHi = 0;
    for(int i = 0; i < cuboids.size() - 1; i++){
        for(int j = 0; j < 3; j++){
            if(cuboids[i][j] < cuboids[i + 1][j]) return tallest;
        }
        maxHi += cuboids[i][2];
    }
    maxHi += cuboids[cuboids.size() - 1][2];


    for(int i = 0; i < cuboids.size(); i++){
        for(int j = 0; j < cuboids.size() - 1; j++){

        }
    }

    return maxHi;

}


int main(){
	//freopen("myInput.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> vec = {{12,76,13},{68,55,30},{48,85,52},{91,7,41},{29,65,35}};




	cout << maxHeight(vec) << endl;

	return 0;
}
