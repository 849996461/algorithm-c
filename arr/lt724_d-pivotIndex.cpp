#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>
#include <iomanip>
#include<queue>
#include<set>
#include<numeric>
#include<unordered_set>
using namespace std;
/**
 * ¼òµ¥
 */
class Solution {

public:
    int pivotIndex(vector<int>& nums) {
        int l = nums.size();
        for (int i = 0; i < l; ++i) {
            nums[i] = (i > 0 ? nums[i - 1] : 0) + nums[i];
        }

        for (int i = 0; i < l; ++i) {
            if ((i > 0 ? nums[i - 1] : 0) == nums[l - 1] - nums[i]) {
                return i;
            }
        }
        return -1;
    }

};


int main(){





}