#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("myInput.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	string temp = "";
	for(char c : s){
        if(c != ' ' && c != '-') temp += c;
	}

	string ans = "";
	for(int i = 0; i < s.length(); i += 3){
        ans += temp[i];
        ans += temp[i + 1];
        ans += temp[i + 2];
        ans += '-';
    }

    ans += temp.substr(ans.length(), temp.length() - ans.length());
    if(ans[ans.length() - 2] == '-'){
        char cTemp = ans[ans.length() - 2];
        ans[ans.length() - 2] = ans[ans.length() - 3];
        ans[ans.length() - 3] = cTemp;
    }

    cout << ans << endl;

	return 0;
}
