#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases() int T; cin >> T; while(T--)


int main(){
	//freopen("myInput.txt", "r", stdin);
	quick;

	cases(){
        string s;
        cin >> s;

        map<char, int> mp;

        for(char c : s) mp[c]++;

        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            while(l < s.length() && s[l] != '(') l++;
            while(r >= 0 && s[r] != ')') r--;
            if(l < r){
                mp[s[l]]--;
                mp[s[r]]--;
                s[l] = '.';
                s[r] = '.';
            }
        }

        char temp = r;

        r = s.length() - 1;
        while(l < r){
            while(l < s.length() && s[l] != '(') l++;
            while(r >= 0 && s[r] != '?') r--;
            if(l < r){
                mp[s[l]]--;
                mp[s[r]]--;
                s[l] = '.';
                s[r] = '.';
            }
        }

        l = 0;
        r = temp;
        while(l < r){
            while(l < s.length() && s[l] != '?') l++;
            while(r >= 0 && s[r] != ')') r--;
            if(l < r){
                mp[s[l]]--;
                mp[s[r]]--;
                s[l] = '.';
                s[r] = '.';
            }
        }

        if(mp['('] > 0 || mp[')'] > 0 || mp['?'] % 2 == 1){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

	}


	return 0;
}
