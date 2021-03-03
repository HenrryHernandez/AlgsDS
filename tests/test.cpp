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

void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                printf("%d ", i);

            else // Otherwise print both
                printf("..%d ..%d ", i, n/i);
        }
    }
}

/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    printDivisors(100);
    return 0;
}


/*
int n, m;
    cin >> n >> m;

    odv initial(n);
    odv desiered(n);
    odv where;

    map<int, int> painters;

    nf(i, 0, n) cin >> initial[i];
    nf(i, 0, n){
        cin >> desiered[i];
        if(initial[i] != desiered[i]){
            where.push_back(i);
        }
    }
    nf(i, 0, m){
        int p;
        cin >> p;
        painters[p]++;
    }

    if(!len(where)){

    }

    for(int i : where){
        if(painters[desiered[i]] <= 0){
             cout << "NO" << endl;
             return;
        }else{
            painters[desiered[i]]--;
        }
    }

    cout << "YES" << endl;
    printVec(where);
    */
