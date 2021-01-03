#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ll long long int;
#define PP pair<ll, ll>
#define len(x) x.size()
#define f(i, x, n) for(int i = x; i < n; i++)

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    set<int> st;
    st.insert(v[0]);

    for(int i = 1; i < n; i++){
        if(st.find(v[i]) != st.end()) v[i]++;
        st.insert(v[i]);
    }

    cout << st.size() << endl;
}

int main(){
	quick;

	cases(solve);

	return 0;
}
