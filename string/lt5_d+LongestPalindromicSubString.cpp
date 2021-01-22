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


/*
 * Longest Palindromic Substring
 * 解法:
 * 1. 单纯的中心拓展 O(n^2)
 * 2. 中心拓展 + 确认对称点 O(n)
 *
 * */
class Solution {
public:
    // 解法一.
    static pair<int,int> expand(int left , int right ,const string& s){
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 2, right - 1};
    }

    //解法二.
    string longestPalindrome(string s) {
        string t = "#";
        for (char i : s) {
            t += i;
            t += '#';
        }
        int center = 0;
        int rEdge = 0;
        int start = 0;
        int end = 0;
        //记录每个点的臂长
        vector<int> ve (t.length());

        for (int i = 0; i < t.length(); ++i) {
            int l = 0;
            if (rEdge > i) {
                //获取对称点
                int symP = center - (i - center);
                l = min({ve[symP], rEdge - i});
            }
            auto [left , right] = expand(i-l,i+l,t);
            ve[i] = right - i;
            if (right - left > end - start) {
                end = right , start = left;
            }
            if (right > rEdge) {
                rEdge = right;
                center = i;
            }
        }
        t = t.substr(start, end - start + 1);
        string res;
        for (char i : t) {
            if (i != '#') {
                res += i;
            }
        }
        return res;


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

//
