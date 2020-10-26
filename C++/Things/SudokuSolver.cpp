#include <bits/stdc++.h>

using namespace std;

/*
    IMPORTANT:
        Data should be inserted by square from left to rigth, top to bottom, that is,
        each vector in vector of vectors is representing a square, not a row or column.

        For example, the next sudoku:
          -------------------
          |0 0 0|0 0 0|0 8 0|
          |6 8 0|4 7 0|0 2 0|
          |0 1 9|5 0 8|6 4 7|
          |-----------------|
          |0 6 0|9 0 0|0 0 4|
          |3 4 2|6 8 0|0 0 0|
          |1 9 0|0 5 0|8 3 0|
          |-----------------|
          |0 0 0|7 2 0|4 0 3|
          |0 0 6|0 0 5|0 1 0|
          |0 0 3|8 9 1|5 0 0|
          -------------------

        should be filled like this:

        [   [0,0,0,6,8,0,0,1,9],
            [0,0,0,4,7,0,5,0,8],
            [0,8,0,0,2,0,6,4,7],
            [0,6,0,3,4,2,1,9,0],
            [9,0,0,6,8,0,0,5,0],
            [0,0,4,0,0,0,8,3,0],
            [0,0,0,0,0,6,0,0,3],
            [7,2,0,0,0,5,8,9,1],
            [4,0,3,0,1,0,5,0,0], ]

        If the sudoku was filled correctly, using the printSudoku() function should print it correctly
        as the sudoku above.


        The algorithm is capable of solving easy and some medium sudokus. As you might see, it's very simple.
        For hard ones, it'd need more tweak
*/


void printSudoku(vector<vector<int>> v, int a, int b, int aa, int bb){
    if(a > 6) return;

    cout << "|";
    for(int i = a; i < b; i++){
        for(int j = aa; j < bb; j++){
            cout << v[i][j];
            if(j + 1 != bb) cout << " ";
        }
        cout << "|";
    }
    cout << endl;

    if(aa == 6){
        cout << "-------------------" << endl;
        printSudoku(v, a + 3, b + 3, 0, 3);
    }else{
        printSudoku(v, a, b, aa + 3, bb + 3);
    }

}

bool checkVerticals(vector<vector<int>> v, int a, int b, int x){
    a %= 3;
    b %= 3;
    bool found = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //cout << v[a][b] << endl;
            if(v[a][b] == x) found = true;
            b += 3;
        }
        a += 3;
        b %= 3;
    }

    return found;
}

bool checkHorizontals(vector<vector<int>> v, int a, int b, int x){
    a = a / 3 * 3;
    b = b / 3 * 3;
    bool found = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //cout << v[a][b] << " ";
            if(v[a][b] == x) found = true;
            b++;
        }
        b--;
        a++;
        b = b / 3 * 3;
    }
    //cout << endl;
    return found;
}

bool checkSquare(vector<vector<int>> v, int a, int x){
    bool found = false;
    for(int b = 0; b < 9; b++){
        //cout << v[a][b];
        if(v[a][b] == x) found = true;
        //if(b % 3 == 2)cout << endl;
        //else cout << " ";
    }
    return found;
}

void solveSudoku(vector<vector<int>> &sudokuBoard){

    // counter of how many little squares have not been solved, that is, that are empty.
    int notSolved = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudokuBoard[i][j] == 0){
                notSolved++;
            }
        }
    }

    // we start to solve
    while(notSolved){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(sudokuBoard[i][j] == 0){
                    int howMany = 0;
                    int candidate = 0;
                    for(int x = 1; x <= 9; x++){
                        if( checkVerticals(sudokuBoard, i, j, x) ||
                            checkHorizontals(sudokuBoard, i, j, x) ||
                            checkSquare(sudokuBoard, i, x))
                        {
                            continue;
                        }else{
                            candidate = x;
                            howMany++;
                        }
                    }
                    if(howMany == 1){
                        sudokuBoard[i][j] = candidate;
                        notSolved--;
                    }
                }
            }
        }
    }
}

int main(){
    //here we just get the data, filled the soduku and that stuff.
    freopen("sudokuInput.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    vector<vector<int>> sudokuBoard;
    for(int i = 0; i < 9; i++){
        vector<int> cVec;
        for(int j = 0; j < 9; j++){
            cin >> c;
            cVec.push_back(c);
        }
        sudokuBoard.push_back(cVec);
    }


    //here is where it starts.
    cout << "-------------------" << endl;
    printSudoku(sudokuBoard, 0, 3, 0, 3);
    cout << endl;

    solveSudoku(sudokuBoard);

    cout << "-------------------" << endl;
    printSudoku(sudokuBoard, 0, 3, 0, 3);
    cout << endl;
/*
    cout << "not solved = " << notSolved << endl;
    int x = 4;
    if(checkVerticals(sudokuBoard, 8, 6, x)) cout << "found" << endl;
    else cout << "not found" << endl;
    cout << endl;
    if(checkHorizontals(sudokuBoard, 7, 2, x)) cout << "found" << endl;
    else cout << "not found" << endl;
    cout << endl;
    if(checkSquare(sudokuBoard, 4, x)) cout << "found" << endl;
    else cout << "not found" << endl;*/



    return 0;
}
