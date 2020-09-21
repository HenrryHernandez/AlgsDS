#include <bits/stdc++.h>

using namespace std;

long long iterativeFibo(long long n){
    if(n == 1 || n == 2)
        return 1;

    long long p = 1;
    long long pp = 1;
    long long x = 0;
    while(n > 2){
        x = p + pp;
        pp = p;
        p = x;
        n--;
    }

    return x;
}

long long recursiveFibo(int n){
    if(n == 1 || n == 2)
        return 1;

    return recursiveFibo(n - 1) + recursiveFibo(n - 2);

}

int main(){

    int n = 100;
    long long x = iterativeFibo(n);
    long long xx = recursiveFibo(n);

    cout << xx << endl;

    return 0;
}
