#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases() int T; cin >> T; while(T--)


int main(){
	//freopen("myInput.txt", "r", stdin);
	quick;

	cases(){
        int redN;
        cin >> redN;
        vector<int> reds(redN);
        for(int i = 0; i < reds.size(); i++){
            cin >> reds[i];
        }
        int blueN;
        cin >> blueN;
        vector<int> blues(blueN);
        for(int i = 0; i < blues.size(); i++){
            cin >> blues[i];
        }

        int bigR = 0;
        int bigB = 0;

        int temp = 0;
        for(int i : reds){
            temp += i;
            if(temp > bigR) bigR = temp;
        }

        temp = 0;
        for(int i : blues){
            temp += i;
            if(temp > bigB) bigB = temp;
        }

        cout << bigR + bigB << endl;
	}


	return 0;
}
