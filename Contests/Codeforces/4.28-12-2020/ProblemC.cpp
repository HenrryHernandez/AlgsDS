#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases() int T; cin >> T; while(T--)

bool fr(int a, int b){
    return abs(a - b) >= 1;
}

bool tr(int k, int h, int hw){
    int temp = h + k + (k - 1);
    return hw <= temp;
}

int main(){
	freopen("myInput.txt", "r", stdin);
	quick;

	cases(){
        int n, k;
        cin >> n >> k;
        vector<int> heights(n);
        for(int i = 0; i < n; i++)
            cin >> heights[i];

        int bef = heights[0] + k;

        bool pos = true;
        int temp;
        for(int i = 1; i < n - 1; i++){
            int c = k - 1;
            temp = heights[i] + k + c;
            while(!fr(bef, temp) && c >= 0){
                c--;
                temp = heights[i] + k + c;
            }

            cout << bef << endl;

            if(!fr(bef, temp)){
                cout << "incomplete" << endl;
                pos = false;
            }

            bef = temp;
        }

        temp = heights[heights.size() - 1] + k;
        if(!fr(bef, temp)){
            cout << "incomplete" << endl;
            pos = false;
        }

        if(!pos)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

	}


	return 0;
}
