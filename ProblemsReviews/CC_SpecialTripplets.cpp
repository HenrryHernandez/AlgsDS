//https://www.codechef.com/AUG21C/problems/SPCTRIPS

#include <bits/stdc++.h>
using namespace std;

#define quick ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cases(c) int T; cin >> T; while(T--) c()

#define ef(i, x, n) for(int i = x; i <= n; i++) //equals for (<=)
#define def(i, x, n, n2) for(int i = x; i <= n; i += n2) //dynamic equals for (<=)

void solve() {
    int n, cnt = 0;
    cin >> n;

    ef(c, 1, n) {
      //we are going to go through all multiples of current c
      //thus, b % c will always be 0
      def(b, c, n, c) {
        def(a, c, n, b) {
          if(a % b == c) cnt++;
        }
      }
    }

    cout << cnt << endl;

    return;
}

int main(){
	freopen("myInput.txt", "r", stdin);
	quick;

	cases(solve);

	return 0;
}
