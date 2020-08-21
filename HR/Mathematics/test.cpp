#include <bits/stdc++.h>

using namespace std;

bool primeNumber(int p){
    for(int i = 2; i < p; i++)
        if(p % i == 0)
            return false;

    return true;
}

int modulo(int g, int x, int p){
    return g * x % p;
}

void numberOfPR(map<int, int> &nPR, int m){
    if(primeNumber(m)){
        nPR[m]++;
        return;
    }

    for(int i = 2; i < m / 2; i++){
        if(m % i == 0){
            nPR[i]++;
            numberOfPR(nPR, m / i);
            break;
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input07.txt", "r", stdin);

    int p = 831143041;
    //cin >> p;

    bool prFound;
    for(int i = 1; i <= p - 1; i++){
        prFound = true;
        map<int, int> theMap;
        int moduleNumber = 1;
        for(int j = 1; j <= p - 2; j++){
            moduleNumber = modulo(i, moduleNumber, p);
            if(theMap[moduleNumber] == 0){
                theMap[moduleNumber] = 1;
            }else{
                prFound = false;
                break;
            }
        }
        if(prFound){
            cout << i << " ";
            break;
        }
    }


    map<int, int> nPR;
    numberOfPR(nPR, p - 1);
    map<int, int>::iterator it = nPR.begin();
    int numberPR = 1;

    while(it != nPR.end()){
        int pn = it->first;
        int pp = it->second;
        numberPR *= (pow(pn, pp - 1))*(pn - 1);
        it++;
    }

    cout << numberPR << " " << endl;

    /*double nPrmRoots = p - 1.0;
    for(int i = 2; i <= p / 2; i++){
        if(primeNumber(i) && (p - 1) % i == 0){
            nPrmRoots *= (1 - (1.0 / i));
        }
    }
    cout << nPrmRoots << endl;*/

    return 0;
}
