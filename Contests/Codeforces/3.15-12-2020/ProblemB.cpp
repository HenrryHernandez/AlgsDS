#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases() int T; cin >> T; while(T--)


int main(){
	//freopen("myInput.txt", "r", stdin);
	quick;

	cases(){
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(
            s.substr(n - 4, 4) == "2020" ||
            s.substr(0, 1) + s.substr(n - 3, 3) == "2020" ||
            s.substr(0, 2) + s.substr(n - 2, 2) == "2020" ||
            s.substr(0, 3) + s.substr(n - 1, 1) == "2020" ||
            s.substr(0, 4) == "2020"
            ) cout << "YES" << endl;
        else cout << "NO" << endl;
	}

	return 0;
}
