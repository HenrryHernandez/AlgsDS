#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases() int T; cin >> T; while(T--)

void reverseString(string &s){
    int l = 0;
    int r = s.length() - 1;

    while(l <= r){
        char c = s[l];
        s[l] = s[r];
        s[r] = c;
        l++;
        r--;
    }
}

int main(){
	//freopen("myInput.txt", "r", stdin);
	quick;
    cases(){
        int x;
        cin >> x;

        string s;
        int n = 9;

        while(x && n){
            if(x - n >= 0){
                s += to_string(n);
                x -= n;
            }
            n--;
        }

        if(!x){
            reverseString(s);
            cout << s << endl;
        }else cout << -1 << endl;
    }

	return 0;
}
