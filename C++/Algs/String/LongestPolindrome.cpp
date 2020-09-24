#include <bits/stdc++.h>

using namespace std;


/*
    My solution
        Time Complexity: O(N*N*N)
        Space Complexity(1)
*/

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0;
    int end = 0;
    int longest = end - start + 1;

    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            if(j - i + 1 > longest && s[i] == s[j]){
                int tempi = i;
                int tempj = j;
                while(tempj >= tempi){
                    if(s[tempi] == s[tempj]){
                        tempi++;
                        tempj--;
                    }else{
                        break;
                    }
                }
                if(tempi > tempj){
                    start = i;
                    end = j;
                    longest = end - start + 1;
                }
            }
        }
    }

    return s.substr(start, longest);
}


/*
    Not my solution
        Time Complexity: O(N*N)
        Space Complexity(N)
*/

int PaliLength(int L, int R, string s)
{
    int len=0;
    while (L>=0&&R<s.size())
    {
        if(s[L]==s[R])
        {
            len=R-L+1;
            L--;
            R++;
        }
        else
          break;
    }
    return len;
}

string longestPalindrome(string s) {
    int start=0; int end=0;
    if(s.size()==0)
        return "";
    else
    {
        int len1;
        int len2;
        for (int center=0;center<s.size();center++)
        {
            len1=PaliLength(center, center, s);
            len2=PaliLength(center, center+1, s);
            int len = max(len1, len2);
            if(len>end-start)
            {
                start=center - ((len - 1) / 2);
                end=center + (len / 2);
            }
        }
    }
    return s.substr(start, end-start+1);
}


/*
    Not my solution -- THE BEST ONE
        Time Complexity: O(N*N)
        Space Complexity(1)
*/



int main(){

    cout << longestPalindrome("abbc") << endl;

    return 0;
}
