#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ll long long int
#define PP pair<ll, ll>
#define len(x) x.size()
#define nf(i, x, n) for(int i = x; i < n; i++) //normal for (<)
#define ef(i, x, n) for(int i = x; i <= n; i++) //equals for (<=)
#define ttf 100001 //two to the five
#define odv vector<int> //one-dimension vector
#define tdv vector<vector<int>> //two-dimension vector
#define fivw(x, y) fill(x.begin(), x.end(), y) //fill vector with
#define initv(x) fivw(x, 0) //initialize vector



/*FUnctions*/
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

ll dfs(vector<vector<int>> &v, int index, vector<int> &colors, vector<int> &weights, int &n){

    ll sum = weights[index];
    for(int i : v[index]){
        if(i > index){
            if(colors[index] == colors[i]){
                sum += dfs(v, i, colors, weights, n);
            }else{
                if(len(v[i]) > 1) sum += weights[i];
                sum += weights[index] + dfs(v, i, colors, weights, n);
            }
        }
    }

    return sum;
}

void solve() {
    int n;
    cin >> n;

    odv weights(n + 1);
    ef(i, 1, n) cin >> weights[i];

    odv colors(n + 1, 1);

    tdv v(n + 1);
    n--;
    while(n--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    n = len(weights) - 1;
    ef(i, 1, len(weights) - 2){
        cout << dfs(v, 1, colors, weights, n) << " ";
        colors[n--] = -1;
    }
    cout << endl;

}

int main(){
	quick;

	cases(solve);

	return 0;
}
