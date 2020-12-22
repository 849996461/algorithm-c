#include <iostream>
#include "unordered_set"
#include "set"
#include "math.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> rem ;
        int ml = 0;
        int rk = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (rk < s.size() && !rem.count(s[rk])) {
                rem.insert(s[rk]);
                rk++;
            }
            ml = max(ml,(int)rem.size());
            rem.erase(s[i]);

        }
        return ml;

    }

};

int main(){
    Solution a = Solution();
    cout << a.lengthOfLongestSubstring("bbbbbcbb") ;
//    unordered_set<int> set = {1, 2, 3, 4, 5};
//    cout << max(1,(int)set.size());

}
