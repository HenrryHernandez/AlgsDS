#include <bits/stdc++.h>

using namespace std;

vector<string> flip(vector<string> grid) {
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[i].length(); j++)
            if(grid[i][j] == 'o'){
                if(i != 0)
                    grid[i - 1][j] = '.';

                if(i != grid.size() - 1 && grid[i + 1][j] != 'o')
                    grid[i + 1][j] = '.';

                if(j != 0)
                    grid[i][j - 1] = '.';

                if(j != grid[0].size() - 1 && grid[i][j + 1] != 'o')
                    grid[i][j + 1] = '.';

                grid[i][j] = '.';
            }

    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) {

    if(n == 1)
        return grid;
    if(n % 2 == 0){
        for(int i = 0; i < grid.size(); i++){
            /*size_t pos;
            while((pos = grid[i].find(".")) != string::npos){
                grid[i].replace(pos, 1, "O");
            }*/
            std::replace(grid[i].begin(), grid[i].end(), '.', 'O');
        }

        return grid;
    }

    for(int i = 0; i < grid.size(); i++){
        std::replace(grid[i].begin(), grid[i].end(), 'O', 'o');
        std::replace(grid[i].begin(), grid[i].end(), '.', 'O');
    }

    grid = flip(grid);

    if((n - 3) % 4 == 0){
        return grid;
    }else{
        for(int i = 0; i < grid.size(); i++){
            std::replace(grid[i].begin(), grid[i].end(), 'O', 'o');
            std::replace(grid[i].begin(), grid[i].end(), '.', 'O');
        }
        return flip(grid);
    }


}

int main(){

    freopen("myInput.txt", "r", stdin);
    int n;
    int rows;
    cin >> rows;
    cin >> n >> n;

    vector<string> grid;
    for(int i = 0; i < rows; i++){
        string x;
        cin >> x;
        grid.push_back(x);
    }

    grid = bomberMan(n, grid);

    for(string st : grid){
        cout << st << endl;
    }




    return 0;
}
