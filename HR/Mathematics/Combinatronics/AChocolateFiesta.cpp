#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

//this part is usful so the number 2^n doesn't grow too huge and, instead, it gets mod with macro 'mod' so we don't
//let it grow too big
long powEsp(int two, int counts){
    for(int i = 0; i < counts; i++){
        two *= 2;
        two %= mod;
    }

    return two;
}

int solve(vector<int> a) {
    int oddsCount = 0;
    int evensCount = 0;

    for(int x : a)
        if(x % 2 != 0)
            oddsCount++;
        else
            evensCount++;

    long odds = powEsp(1, oddsCount - 1);
    long evens = powEsp(1, evensCount);

    return (odds * evens - 1) % mod;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input10.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> vec;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    cout << solve(vec) << endl;

    return 0;
}

