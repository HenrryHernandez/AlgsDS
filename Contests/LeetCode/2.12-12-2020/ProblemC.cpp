#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVec(vector<T> &v){
    for(T i : v){
        cout << i << endl;
    }
    cout << endl;
}

class Solution {
	int n, INF = 1E9;
	vector<int> a, s;
	vector<vector<int>> dp;

	int solve(int l, int r) {
		if (dp[l][r] != -INF) return dp[l][r];

		if (l == r) return 0;
		else {
			int x1, x2;
			x1 = s[r] - s[l] - solve(l + 1, r);
			x2 = s[r - 1] - s[l - 1] - solve(l, r - 1);
			dp[l][r] = max(x1, x2);
			return dp[l][r];
		}
	}

public:
	int stoneGameVII(vector<int>& stones) {
		n = stones.size();
		a = stones;
		s.resize(n + 1);
		s[0] = 0;
		for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

		dp.assign(n + 1, vector<int>(n + 1, -INF));

		int ans = solve(1, n);
		return ans;
	}
};

int main(){
	//freopen("myInput.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v = {7,90,5,1,100,10,10,2};
	cout << Solution().stoneGameVII(v) << endl;

	return 0;
}
