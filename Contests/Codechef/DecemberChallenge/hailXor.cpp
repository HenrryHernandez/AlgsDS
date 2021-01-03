#include <bits/stdc++.h>

using namespace std;

void swapEm(int &a, int &b){ ///////////////// o(1)
    int temp = a;
    a = b;
    b = temp;
}

void printVec(vector<int> &v){ ///////////////// o(n)
    for(int i : v){
        cout << i << " ";
    cout << endl;
}

void checkWithRemainings(vector<int> &v, int &a){ //O(n log(n))
    int temp = a;

    for(int i = 0; i < v.size(); i++){
        a ^= v[i];
        if(a > temp) a = temp;
        else{
            printVec(v);
            cout << "check with remainigs" << endl;
            temp = a;
            swapEm(v[i], v[v.size() - 1]);
            v.pop_back();
            i--;
            printVec(v);
        }

        if(!a) break;
    }
}

void resolve(int &a, vector<int> &v, int &X){
    int powerOfTwo = 30;

    int temp = a;
    while(a && X){
        a ^= (int)pow(2, powerOfTwo);
        if(a > temp) a = temp;
        else{
            X--;
            cout << "X = " << X << endl;
            v.push_back((int)pow(2, powerOfTwo));
            temp = a;
        }
        powerOfTwo--;
    }
}

void emptyRemainingsOn(int &a, vector<int> &v){ ///////////////// o(log n)
    cout << "emptying to " << a << endl;
    for(int i : v)
        a ^= i;
}

void resolveWithLastTwo(int &a, int &b, int &X){
    int powerOfTwo = 30;

    int temp = a;
    while(X && a){
        a ^= (int)pow(2, powerOfTwo);
        if(a > temp) a = temp;
        else{
            X--;
            b ^= (int)pow(2, powerOfTwo);
        }
        powerOfTwo--;
    }

    if(X % 2 == 0) return;

    a ^= 1;
    b ^= 1;
}

void hailXor(int N, int X){
    vector<int> remainings;
    vector<int> result;

    int a;
    while(N && X){
        cin >> a;
        cout << "a = " << a << endl;

        checkWithRemainings(remainings, a);
        if(N != 1) resolve(a, remainings, X);

        result.push_back(a);
        N--;
    }

    while(N){
        cin >> a;
        checkWithRemainings(remainings, a);
        result.push_back(a);

        N--;
    }

    emptyRemainingsOn(result[result.size() - 1], remainings);

    resolveWithLastTwo(result[result.size() - 2], result[result.size() - 1], X);

    cout << "result           = " << endl;
    printVec(result);

}

int main(){
	freopen("myInput.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while(T--){
        int N, X;
        cin >> N >> X;

        hailXor(N, X);
	}


	return 0;
}
