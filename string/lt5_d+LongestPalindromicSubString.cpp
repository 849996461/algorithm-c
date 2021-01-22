#include <iostream>
#include "unordered_set"
#include "set"
#include "math.h"
using namespace std;

/*
 * Longest Palindromic Substring
 * 解法:
 * 1. 单纯的中心拓展 O(n^2)
 * 2. 中心拓展 + 确认对称点 O(n)
 *
 *
 * */
//
class Solution {
public:
    //解法二.
    string longestPalindrome(string s) {
        string t = "#";
        for (int i = 0; i < s.length(); ++i) {
            t += s[i] + '#';
        }
        int p = 0;
        int rEdge = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < t.length(); ++i) {
            auto [left , right] = expand(i,i,t);
            if (right - left > end - start) {
                end = right , start = left;
            }
            if (right > rEdge) {
                rEdge = right;
            }
        }
        return t.substr(start, end - start + 1).replace()


    }








    // 解法一.
    pair<int,int> expand(int left , int right ,const string& s){
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome1(string s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length()-1; ++i) {
            auto [left1 , right1] = expand(i, i + 1, s);
            auto [left2 , right2] = expand(i, i, s);
            if (right1 - left1 > (end - start)) {
                start = left1 , end = right1;
            }
            if (right2 - left2 > (end - start)) {
                start = left2 , end = right2;
            }

        }
        return s.substr(start,end-start+1);
    }

};

int main(){
    Solution a = Solution();
    string s = "12344321";
    cout << a.longestPalindrome(s) ;

}

