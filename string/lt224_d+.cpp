#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>
#include <iomanip>
#include<queue>
#include<set>
#include "stack"
#include<numeric>
#include<unordered_set>
#include<unordered_map>
using namespace std;
/**
 * +-·¨¼ÆËãÆ÷
 */
class Solution {
public:

	int calculate(string s) {
		int positive = 1;
		int res = 0;
		stack<int> sta;
		sta.push(1);
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			 if (c == '(') {
				 sta.push( positive);
			} else if (c == ')') {
				 sta.pop();
				 positive = sta.top();
			 } else if (c == '+' || c == ' ') {
				 continue;
			 } else if (c == '-') {
				 positive = -1 * sta.top();
			 } else {
				 int num = s[i] - 48;
				 while (i < s.size() - 1 && s[i + 1] < 58 && s[i + 1] >= 48) {
					 num = num * 10 + (s[i + 1] - 48);
					 i++;
				 }
				 res += num * positive;
				 positive = sta.top();
			 }
		}
		return res;
	}
};


int main(){

	Solution solution;
	cout << solution.calculate("(7)-(0)+(4)"
	);

}




