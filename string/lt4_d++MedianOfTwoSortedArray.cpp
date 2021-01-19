#include <iostream>
#include "unordered_set"
#include "set"
#include "math.h"
using namespace std;

/*
 * Median of Two Sorted Arrays
 * 解法:二分法
 *
 * */
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int sum = nums1.size() + nums2.size();
        int half = sum / 2;
        int left = 0;
        int right = nums1.size();
        int lMax = 0;
        int rMin = 0;

        while (left <= right) {
            int i = (left + right) >> 1;
            int j = half - i;
            //i 整体太大

            int li = i == 0 ? INT_MIN : nums1[i - 1];
            int ri = i == nums1.size() ? INT_MAX : nums1[i];
            int lj = j == 0 ? INT_MIN : nums2[j - 1];
            int rj = j == nums2.size() ? INT_MAX : nums2[j];

            if (li < rj){
                lMax = max(li, lj);
                rMin = min(ri, rj);
                left = i + 1;
            }else{
                right = i - 1;
            }

        }
        return sum % 2 == 0 ? (lMax + rMin) / 2.0 : rMin;
    }
};

int main(){
    Solution a = Solution();
    vector<int> v1({1, 2});
    vector<int> v2({3, 4});

    cout << a.findMedianSortedArrays(v1,v2) ;

}

