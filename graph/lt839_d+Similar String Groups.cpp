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
 * 给定同长只有字符顺序不同的一系列字符串 , 有两个字符同则相似
 * 返回相似组数量
 *
 */
class Uset{
private:
	vector<int> parent;
	int sum;

public:
	Uset(int n) : parent(n), sum(n) {
		for (int i = 1; i < n; ++i) {
			parent[i] = i;
		}
	}
	int find(int x){
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}

	bool connect(int x, int y){
		int xx = find(x), yy = find(y);
		return xx == yy;
	}

	void merge(int x, int y) {
		int xx = find(x), yy = find(y);
		if (xx == yy) {
			return;
		}else{
			sum--;
			parent[xx] = yy;
		}
	}
	int getSum(){
		return sum;
	}

};

class Solution {
public:
	bool checkSim(string &s1, string &s2){
		int num = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) {
				num++;
			}
			if (num > 2) {
				return false;
			}
		}
		return true;
	}
	int numSimilarGroups(vector<string>& strs) {
		int l = strs.size();
		Uset uset(l);
		for (int i = 0; i < l; ++i) {
			for (int j = i+1; j < l; ++j) {
				if (checkSim(strs[i], strs[j])) {
					uset.merge(i, j);
				}
			}
		}
		return uset.getSum();

	}
};

int main(){
    Solution solution;
	vector<vector<int>> arr{{1, 2},
							{2, 3}};

	cout << solution.swimInWater(arr);
	string a = "dsa";
}




