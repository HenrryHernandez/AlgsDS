//https://codeforces.com/contest/1551/problem/B2

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
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> mp;

  int cnt = 0;
  nf(i, 0, n) {
    int temp; 
    cin >> temp;

    //since we can just print a same number up to k different colors, 
    //we'll take the first k occurences and leave the rest out
    if(mp[temp].size() < k) {
      mp[temp].push_back(i);
      cnt++;
    }
  }

  //we have to leave cnt in multiples of k, that means if cnt was 17 and k was 16
  //we have to remove 1 from cnt (17) so we have the multiple of k (16)
  cnt -= cnt % k;

  vector<int> ans(n);

  //once we have the multiple of k we are gonna be able to have a grid of m * n
  //where m = k and n = k / cnt
  //the grid will be filled vertical, that is, col by col
  int i = cnt / k;
  while(i--) {
    int color = 0;
    while(color < k) {
      auto itr = mp.begin();
      
      //once we finish with the occurences of a number, we delete it 
      //and continue with the next one to keep filling the curent col
      if(itr->second.empty()) {
        mp.erase(itr);
        continue;
      }
      color++;
      ans[itr->second.back()] = color;
      itr->second.pop_back();
    }
  }

  printVec(ans);
}

int main(){
	freopen("myInput.txt", "r", stdin);
	quick;

	cases(solve);

	return 0;
}
