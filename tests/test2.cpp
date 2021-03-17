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

int firstC(int N, int E, int H, int A, int B, int C){
   int ans = 0;
   
   int min = min(E, H);
   E -= min;
   H -= min;
   
   if(min >= C){
       return N * C;
   }
   
   ans += N * C;
   N -= min;
   
   if(!E && N > (H / 3)){
       ans += N * B;
   }else if(!H && N > (E / 2)){
       ans += N * A;
   }else{
       ans = -1;
   }
   
   return ans;
}

int thirdC(){
    
}

void solve() {
    int N, E, H, A, B, C;
    cin >> N >> E >> H >> A >> B >> C;
    
    if(C <= A && C <= B){
        cout << firstC() << endl;
        return;
    }else if(C > A && C > B){
        cout << thirdC() << endl;
        return;
    }else{
        cout << secondC() << endl;
        return;
    }
}

int main(){
	quick;

	cases(solve);

	return 0;
}

