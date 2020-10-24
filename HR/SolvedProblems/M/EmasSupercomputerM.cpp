#include <bits/stdc++.h>

using namespace std;

int getFins(vector<string> &v, int y, int x){
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    int xItr, yItr;
    int shorest = 0;

    xItr = x;
    yItr = y - 1;
    while(yItr >= 0 && v[yItr][xItr] != 'B'){ //check up
        c1++;
        yItr--;
    }

    xItr = x;
    yItr = y + 1;
    while(yItr < v.size() && v[yItr][xItr] != 'B'){ //check down
        c2++;
        yItr++;
    }

    xItr = x - 1;
    yItr = y;
    while(xItr >= 0 && v[yItr][xItr] != 'B'){ //check left
        c3++;
        xItr--;
    }

    xItr = x + 1;
    yItr = y;
    while(xItr < v[0].size() && v[yItr][xItr] != 'B'){ //check right
        c4++;
        xItr++;
    }

    shorest = min(min(c1, c2), min(c3, c4));
    return shorest;
}

int makeCross(vector<string> &v, int y, int x, int shorest){
    for(int i = 0; i <= shorest; i++){
        v[y - i][x] = 'B';
        v[y + i][x] = 'B';
        v[y][x - i] = 'B';
        v[y][x + i] = 'B';
    }

    return shorest * 4 + 1;
}

int twoPluses(vector<string> grid) {
    int biggest = 0, secondBiggest = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 'G'){
                for(int k = 0; k <= getFins(grid, i, j); k++){
                    vector<string> v = grid;
                    int tempBiggest = makeCross(v, i, j, k);
                    int j2 = j + 1;
                    for(int ii = i; ii < grid.size(); ii++){
                        for(int jj = j2; jj < grid[0].size(); jj++){
                            if(v[ii][jj] == 'G'){
                                for(int kk = 0; kk <= getFins(v, ii, jj); kk++){
                                    vector<string> vv = v;
                                    int tempSecondBiggest = makeCross(vv, ii, jj, kk);
                                    if(tempBiggest * tempSecondBiggest > biggest * secondBiggest){
                                        biggest = tempBiggest;
                                        secondBiggest = tempSecondBiggest;
                                    }
                                }
                            }
                        }
                        j2 = 0;
                    }
                }
            }
        }
    }

    return biggest * secondBiggest;
}

int main(){
    freopen("myInput.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m;

    vector<string> sVec(n);
    for(int i = 0; i < n; i++){
        cin >> s;
        sVec[i] = s;
    }

    cout << twoPluses(sVec) << endl;

    return 0;
}
