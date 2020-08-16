#include <bits/stdc++.h>

using namespace std;

#define LOG(st, x, br) cout << st << x << br;


vector<int> absolutePermutation(int n, int k){

        vector<int> r;

        if(k == 0){
            for(int i = 1; i <= n; i++){
                r.push_back(i);
            }
            return r;
        }else if(n % 2 != 0 || k > n / 2 || n % (k * 2) != 0){
            r.push_back(-1);
            return r;
        }


        int cVal = -1;
        for(int i = 1; i <= n; i++){
            r.push_back(i + k);
            if(i % abs(k) == 0){
                k *= cVal;
            }
        }

        return r;

}

int main(){

    //freopen("input12.txt", "r", stdin);
    int times;
    cin >> times;
    //LOG("times = ", times, "\n");

    for(int t = 0; t < times; t++){
        int n;
        int k;
        cin >> n >> k;
        //LOG("n = ", n, "\n");
        //LOG("k = ", k, "\n");


        vector<int> r = absolutePermutation(n, k);

        for(int x : r){
            LOG("" ,x, " ");
        }

        cout << endl;

    }


    return 0;
}
