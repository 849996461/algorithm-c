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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int sum ;
        vector<int> res;
        for (int i = A.size()-1; i >= 0; --i) {
            sum = A[i] + K % 10;
            K/=10;
            if (sum >= 10) {
                K+=1;
                sum %= 10;
            }
            res.push_back(sum);
        }
        for (; K > 0; K /= 10) {
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};

int main() {
    Solution a = Solution();
    vector<int> v({1,2,0,0});
    auto res = a.addToArrayForm(v, 34);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
    }

}
