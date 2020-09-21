#include <bits/stdc++.h>

using namespace std;

//Complexity: log(n + m)

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();

    int startt = 0;
    int endd = x;

    while(startt <= endd){
        int partitionX = (startt + endd) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            if((x + y) % 2 == 0){
                return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }else{
                return (double)max(maxLeftX, maxLeftY);
            }
        }else if(maxLeftX > minRightY){
            endd = partitionX - 1;
        }else{
            startt = partitionX + 1;
        }

    }

}

int main(){

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    //  1, 2, 7, 8, 9, 11, 15, 18, 19, 21, 25

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;

}
