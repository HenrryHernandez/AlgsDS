#include <bits/stdc++.h>

using namespace std;

int twoPluses(vector<string> grid) {
    int biggest = 0, secondBiggest = 0;

    for(int i = 1; i < grid.size() - 1; i++)
        for(int j = 1; j < grid[0].length() - 1; j++){

            int c = 0, c2 = 0;
            if(grid[i][j] == 'G'){
                //LEFT-CHECK
                for(int k = j - 1; k >= 0; k--){
                    if(grid[i][k] == 'B'){
                        break;
                    }
                    c++;
                }

                if(c == 0)
                    continue;

                //RIGHT-CHECK
                for(int k = j + 1; k < grid[0].size(); k++){
                    if(grid[i][k] == 'B'){
                        break;
                    }
                    c2++;
                }
                if(c2 == 0){
                    c = c2;
                    continue;
                }else{
                    c = min(c, c2);
                    c2 = 0;
                }

                //UP-CHECK
                for(int k = i - 1; k >= 0; k--){
                    if(grid[k][j] == 'B')
                        break;
                    c2++;
                }
                if(c2 == 0){
                    c = c2;
                    continue;
                }else{
                    c = min(c, c2);
                    c2 = 0;
                }

                //DOWN-CHECK
                for(int k = j - 1; k < grid.size(); k++){
                    if(grid[k][j] == 'B')
                        break;
                    c2++;
                }
            }

            c = min(c, c2) * 4 + 1;

            if(c > biggest){
                secondBiggest = biggest;
                biggest = c;
            }else if(c > secondBiggest)
                secondBiggest = c;
        }

    return biggest * secondBiggest;

}

int main(){

    int n, m;

    freopen("myInput.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);

    vector<string> sVec;
    for(int i = 0; i < n; i++){
        char st[15];
        scanf("%s", &st);
        sVec.push_back(st);
    }

    int r = twoPluses(sVec);

    cout << r << endl;

    return 0;
}
