#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ll long long int
#define PP pair<ll, ll>
#define INF 1e9 + 10
#define len(x) x.size()
#define pb push_back
#define bf(i, x, n) for(int i = x; i < n; i++) //basic for (<)
#define dbf(i, x, n, n2) for(int i = x; i < n; i += n2) //dynamic basic for (<)
#define ef(i, x, n) for(int i = x; i <= n; i++) //equals for (<=)
#define def(i, x, n, n2) for(int i = x; i <= n; i += n2) //dynamic equals for (<=)
#define rbf(i, x, n) for(int i = x; i > n; i--) //reverse basic for (>)
#define ref(i, x, n) for(int i = x; i >= n; i--) //reverse equals for (>=)
#define odv vector<int> //one-dimension vector
#define tdv vector<vector<int>> //two-dimension vector
#define fivw(x, y) fill(x.begin(), x.end(), y) //fill vector with
#define initv(x) fivw(x, 0) //initialize vector
#define svec(v) sort(v.begin(), v.end()) //sort vector
#define rsvec(v) sort(v.rbegin(), v.rend()) //reverse-sort vector
#define fillArr(arr, n) bf(i, 0, n) cin >> arr[i];
#define lcm(x, y) ((x * y) / __gcd(x, y))

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

int nc2(int n) {
    return n * (n - 1) / 2;
}

//get smallest prime factors of numbers from 2 to n
vector<int> getSPFs(int n) {
    vector<int> spf(n + 1, -1);

    for (int i = 2; i <= n; i++) {
        if (spf[i] == -1) {
            for (int j = i; j <= n; j += i) {
                if (spf[j] == -1) spf[j] = i;
            }
        }
    }

    return spf;
}

set<int> get_odd_factors(int n) {
    vector<int> spf; // = getSPFs(n);
    map<int, int> factors;
    while (n > 1) {
        factors[spf[n]]++;
        n /= spf[n];
    }
    
    set<int> odd_factors;
    for (auto [factor, power] : factors) {
        if (power % 2 == 1) {
            odd_factors.insert(factor);
        }
    }
    
    return odd_factors;
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

struct cmpPP {
    bool operator() (const PP& a, const PP& b)
    {
        if(a.first < b.first) return true;
        else if(b.first < a.first) return false;
        else {
            return a.second < b.second;
        }
    }
};

bool cmpDigStrs (string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
};


double roundUpTo2(double n){
    n *= 1000;
    int temp = (int)n;
    if(temp % 10 >= 5) temp += 10;
    temp /= 10;
    n = (double)temp / 100;
    return n;
}

bool binarySearch(vector<int> &v, int l, int r, int num) {
   if (l <= r) {
      int mid = (l + r) / 2;
      if (v[mid] == num)
         return true;
      if (v[mid] > num)
         return binarySearch(v, l, mid - 1, num);
      if (v[mid] < num)
         return binarySearch(v, mid + 1, r, num);
   }
   return false;
}

bool isPerfectSquare(int n){
    double guess = sqrt(n);
    int r = floor(guess);
    if(r*r == n) return true;
    else {
        r = ceil(guess);
        return r*r == n;
    }
}

string getBinaryRepr(int n, int digits) {
    string s = "";

    int i = 0;
    while (n > 0) {
        s += to_string(n % 2);
        n = n / 2;
        i++;
    }

    for(int j = 0; j < digits - i; j++) s += "0";

    reverse(s.begin(), s.end());

    return s;
}

struct Course {
    int e,t,p,index;
};

odv getTime(vector<Course>& courses) {
    int n = courses.size();
    int m = 100;
    tdv dp(n + 1, vector<int>(m + 1, INF));
    
    ef(i,1,n) {
        Course cur = courses[i - 1];
        ef(j,1,m) {
            if(cur.p >= j) {
                int a = dp[i - 1][j];
                int b = cur.t;
                dp[i][j] = min(a, b);
            } else {
                int a = dp[i - 1][j];
                int b = dp[i - 1][j - cur.p] + cur.t;
                dp[i][j] = min(a, b);
            }
        }
    }
    
    if(dp[n][m] == INF) return {-1};
    
    odv ans;
    ans.pb(dp[n][m]);
    
    int i = n;
    int j = m;
    while(i > 0 && j > 0) {
        if(dp[i][j] != dp[i - 1][j]) {
            ans.pb(courses[i - 1].index);
            j -= courses[i - 1].p;
            i--;
        } else {
            i--;
        }
    }
    
    return ans;
}

void solve() {

    return;
}

int main(){
	freopen("myInput.txt", "r", stdin);
	quick;

	cases(solve);

	return 0;
}
