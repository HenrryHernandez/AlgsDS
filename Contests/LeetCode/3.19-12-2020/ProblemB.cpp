#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("myInput.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> nums = {4,2,4,5,6};
    set<int> st;

    int bestOne = 0;

    int temp = 0;
    int lT = 0;
    for(int i = 0; i < nums.size(); i++){
        if(st.find(nums[i]) != st.end()){
            if(temp > bestOne) bestOne = temp;

            while(nums[lT] != nums[i]){
                temp -= nums[lT];
                st.erase(nums[lT]);
                lT++;
            }
            temp -= nums[lT];
            st.erase(nums[lT]);
            lT = i;
        }

        temp += nums[i];
        st.insert(nums[i]);
    }

    return max(temp, bestOne);

	return 0;
}
