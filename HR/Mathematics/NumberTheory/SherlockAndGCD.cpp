#include <bits/stdc++.h>

using namespace std;

//with this we get the GCD(Gratest Common Divisor) of two numbers
int gcd(int a, int b) {
   if (b == 0)
        return a;
   return gcd(b, a % b);
}

//with this we get the GCD of a n numbers; that was, basically, what the 
//challenge asked us for
string solve(vector<int> a) {
    int gcdIs = gcd(a[0], a[1]);
    for(int i = 2; i < a.size(); i++){
        gcdIs = gcd(gcdIs, a[i]);
        if(gcdIs == 1)
            return "YES";
    }

    return "NO";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> vec;
        int number;
        for(int j = 0; j < n; j++){
            cin >> number;
            vec.push_back(number);
        }
        cout << solve(vec) << endl;
    }

    return 0;
}

