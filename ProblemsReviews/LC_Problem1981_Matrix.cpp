//1st place code, contest 255
//https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

#define len(x) x.size()
#define odv vector<int> //one-dimension vector

//the thing is that we don't actually save the sum in a variable,
//we go filling a one-dimension array with the current sum, setting 1s
//in the index corresponding to that sum to indicate that a sum of numbers
//gave that result. i.e. 5 + 14 = 19 so we set 1 in the array at index 19.
//We iterate through each column from each row, starting from the 1st one,
//that means that at the end, when we're at the last row, we'll have all the
//possible sums that could be gotten from all the sums of the previous row,
//again, represented with 1s set in the corresponding sums

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        odv from(5050, 0);
        from[0] = 1;

        int i;
        for(odv v : mat) {
            odv to(5050, 0);
            for(int a : v) {
                for(i = 0; i < 5000; i++)
                    if(from[i]) to[i + a] = 1;
            }

            swap(from, to);
        }

        int mi = 101010;
        for(i = 0; i < 5050; i++)
            if(from[i]) mi = min(mi, abs(target - i));
        
        return mi;
    }
};