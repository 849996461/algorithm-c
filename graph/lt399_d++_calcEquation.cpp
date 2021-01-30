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
#include<unordered_map>
using namespace std;
/**
 * 给出不同变量[<a,b>] , 及其 a/b的值
 * 求出任意变量 x/y的值
 * 解法:并查集
 */
class Uset{
private:
	unordered_map<string,string> parent;
	unordered_map<string,double> deep;

public:
	Uset() : parent(), deep() {

	}

	string find(string& x){
		if(parent.find(x) == parent.end()) {
			parent[x] = x;
			deep[x] = 1;
		}
		if (x != parent[x]) {
			string temp = find(parent[x]);
			deep[x] *= deep[parent[x]];
			parent[x] = temp;
		}
		return parent[x];
	}

	double getDeep(string& x) {
		find(x);
		return deep[x];
	}

	double query(string& x, string& y) {
		if (parent.find(x) == parent.end() || parent.find(y) == parent.end()) {
			return -1;
		}
		if (connect(x, y)) {
			return getDeep(x) / getDeep(y);
		}
		return -1;
	}

	bool connect(string& x, string& y){
		string xx = find(x), yy = find(y);
		return xx == yy;
	}

	void merge(string& x, string& y,double val) {
		string xx = find(x), yy = find(y);
		if (xx == yy) {
			return;
		}else{
			deep[xx] = val / deep[x] * deep[y];
			parent[xx] = yy;
		}
	}

};
class Solution {
public:
	vector<double>
	calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
		Uset uset;
		for (int i = 0; i < equations.size(); ++i) {
			string x = equations[i][0];
			string y = equations[i][1];
			uset.merge(x, y, values[i]);
		}
		vector<double> ans;;
		for (int i = 0; i < queries.size(); ++i) {
			string x = queries[i][0];
			string y = queries[i][1];
			ans.emplace_back(uset.query(x, y));
		}
		return ans;

	}
};


int main(){
	//[["a","b"],["e","f"],["b","e"]]
	//[3.4,1.4,2.3]
	//[["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]
	Solution solution;
	vector<vector<string>> equations{{"a", "b"},
									 {"e", "f"},
									 {"b", "e"}};

	vector<vector<string>> queries{{"b", "a"},
								   {"a", "f"},
								   {"f", "f"},
								   {"e", "e"},
								   {"c", "c"},
								   {"a", "c"},
								   {"f", "e"}};
	vector<double> values{3.4, 1.4, 2.3};
	auto res = solution.calcEquation(equations, values, queries);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}




