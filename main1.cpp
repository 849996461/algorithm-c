#include <iostream>
#include "unordered_set"
#include "set"
#include "math.h"
#include "vector"
#include "list"
#include "algorithm"

using namespace std;



class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int max2 = nums[l-1] * nums[l-2] * nums[l-3];
        int max4 = nums[l-1] * nums[1] * nums[0];
        return max({ max2, max4});

    }
};

int main() {
    Solution a = Solution();
//    cout << a.zigzagLevelOrder();
//    unordered_set<int> set = {1, 2, 3, 4, 5};
//    cout << max(1,(int)set.size());

}
