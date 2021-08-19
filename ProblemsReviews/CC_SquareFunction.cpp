//https://www.codechef.com/START8C/problems/SQUAREFU
//code from: https://www.codechef.com/viewsolution/49870632

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;
vector<int> spf(N + 1, -1);

int nc2(int n) {
    return n * (n - 1) / 2;
}

set<int> get_odd_factors(int n) {
    cout << n << endl;
    
    map<int, int> factors;
    while (n > 1) {
        factors[spf[n]]++;
        n /= spf[n];
    }
    
    set<int> odd_factors;
    for (auto [factor, power] : factors) {
        if (power % 2 == 1) {
            cout << factor << " " << power << endl;
            odd_factors.insert(factor);
        }
    }
    
    cout << odd_factors.size() << endl;
    
    cout << "------------" << endl;
    
    return odd_factors;
}

void solve() {
    
    int n;
    cin >> n;
    
    map<set<int>, int> freqs;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freqs[get_odd_factors(x)]++;
    }
    
    cout << "freqs size = " << freqs.size() << endl;
    
    int ans = 0;
    for (auto [temp, freq] : freqs) {
        ans += nc2(freq);
    }
    
    cout << nc2(n) - ans << '\n';
}

int32_t main() {
    
    for (int i = 2; i <= N; i++) {
        if (spf[i] == -1) {
            for (int j = i; j <= N; j += i) {
                if (spf[j] == -1) spf[j] = i;
            }
        }
    }
    
    int t;
    cin >> t;
    while (t--) solve();
}