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
 * 从 [1,0] -> [x-1,y-1]
 * 每个格子有不同的海拔 , 每天海拔都0 , 多多少起点和终点连通
 */
class Uset{
private:
	vector<int> parent;
public:
	Uset(int n): parent(n){
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	int find(int x){
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}

	bool merge(int x ,int y){
		int xx = find(x), yy = find(y);
		if (xx == yy) {
			return true;
		}
		parent[yy] = xx;
		return false;
	}



};
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int x = edges.size();
		Uset uset(x+1);
		for (int i = 0; i < x; ++i) {
			if(uset.merge(edges[i][0], edges[i][1])){
				return edges[i];
			}
		}
		return {-1, -1};
	}
};


int main(){
	//[["a","b"],["e","f"],["b","e"]]
	//[3.4,1.4,2.3]
	//[["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]

	Solution solution;
	vector<vector<int>> v{{1, 2},
						  {1, 3},
						  {2, 3}};
	auto res =  solution.findRedundantConnection(v);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i];
	}

}




