#include <bits/stdc++.h>

using namespace std;

string canConstruct(vector<int> a) {
    int sum;
    for(int i : a)
        sum += i;
    if(sum % 3 == 0)
        return "YES";

    return "NO";


}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("myInput.txt", "r", stdin);

    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> vec;
        int number;
        for(int j = 0; j < n; j++){
            cin >> number;
            vec.push_back(number);
        }
        cout << canConstruct(vec) << endl;
    }asdsada

    return 0;
}
