#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ll long long int
#define PP pair<ll, ll>
#define ttf 100001 //two to the five
#define len(x) x.size()
#define nf(i, x, n) for(int i = x; i < n; i++) //normal for (<)
#define ef(i, x, n) for(int i = x; i <= n; i++) //equals for (<=)
#define rnf(i, x, n) for(int i = x; i > n; i--) //reverse normal for (>)
#define ref(i, x, n) for(int i = x; i >= n; i--) //reverse equals for (>=)
#define odv vector<int> //one-dimension vector
#define tdv vector<vector<int>> //two-dimension vector
#define fivw(x, y) fill(x.begin(), x.end(), y) //fill vector with
#define initv(x) fivw(x, 0) //initialize vector
#define svec(v) sort(v.begin(), v.end()) //sort vector
#define rsvec(v) sort(v.rbegin(), v.rend()) //reverse-sort vector

/*Functions*/
template <typename T>
void printVec(vector<T> &v){
    for(T i : v){
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void printVec2(vector<vector<T>> &vv){
    for(vector<T> v : vv){
        for(T i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}

bool isPalindrome(string &s){
    int l = 0;
    int r = len(s) - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

void solve() {

}

int main(){
	freopen("myInput.txt", "r", stdin);
	quick;

	cases(solve);

	return 0;
}
