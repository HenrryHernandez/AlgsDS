//Maximum Side Length of a Square with Sum Less than or Equal to Threshold
//https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/


#define len(x) x.size()
#define nf(i, x, n) for(int i = x; i < n; i++) //normal for (<)
#define tdv vector<vector<int>> //two-dimension vector

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = len(mat);
        int m = len(mat[0]);

        tdv v(n + 1, vector<int>(m + 1, 0));

        int max = 0;

        nf(i, 0, n) {
          nf(j, 0, m) {
            v[i + 1][j + 1] = v[i + 1][j] + v[i][j + 1] - v[i][j] + mat[i][j];

            if( i - max >= 0 && j - max >= 0 &&
                v[i + 1][j + 1] - [i - max][j + 1] - v[i + 1][j - max] + v[i - max][j - max] <= threshold
            ) max++;
          }
        }

        return max;
    }
};