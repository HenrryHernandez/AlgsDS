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
        vector<int> v(n);

        int i = 0;
        for(; i < n; i += 2){
            cin >> v[i];
        }

        i -= 2;
        if(n % 2 == 0) i++;
        else i--;

        for(; i >= 0; i -= 2){
            cin >> v[i];
        }

        for(int i : v)
            cout << i << " ";

        cout << endl;

	}

	return 0;
}
