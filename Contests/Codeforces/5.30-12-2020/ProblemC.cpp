#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ll long long int;
#define PP pair<ll, ll>
#define len(x) x.size()
#define f(i, x, n) for(int i = x; i < n; i++)

bool palindrome(string s){
    int l = 0;
    int r = s.size() - 1;

    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }

    return true;
}

void solve() {
    string s;
    cin >> s;

    vector<int> changed(len(s), 0);
    if(len(s) > 1 && s[0] == s[1]){
        changed[1] = 1;
    }

    for(int i = 2; i < len(s); i++){
        if(s[i] == s[i - 2] && !changed[i - 2]) changed[i] = 1;
        if(s[i] == s[i - 1] && !changed[i - 1]) changed[i] = 1;
    }

    int c = 0;
    for(int i : changed) c += i;
    cout << c << endl;

}

int main(){
	quick;

	cases(solve);

	return 0;
}
