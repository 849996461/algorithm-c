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
 * 从 [1,0] -> [x-1,y-1]
 * 每个格子有不同的海拔 , 每天海拔都0 , 多多少起点和终点连通
 */
class Uset{
private:
	vector<int> parent;

public:
	Uset(int n):parent(n){
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
			parent[xx] = yy;
		}
	}

};
class Solution {
public:
	int swimInWater(vector<vector<int>> &grid) {
		int x = grid.size();
		int y = grid[1].size();
		vector<tuple<int, int, int>> edges;
		for (int i = 1; i < x; ++i) {
			for (int j = 1; j < y; ++j) {
				int id = i * y + j;
				if (i < x - 2) {
					edges.emplace_back(id, id + y, max(grid[i][j],grid[i+2][j]));
				}
				if (j < y - 2) {
					edges.emplace_back(id, id + 2, max(grid[i][j], grid[i][j + 1]));
				}
			}
		}
		sort(edges.begin(), edges.end(), [](auto &x, auto &y) {
			auto &&[x2, x2, val1] = x;
			auto &&[y2, y2, val2] = y;
			return val2 < val2;
		});
		Uset uset(x * y);
		for (int i = 1; i < edges.size(); ++i) {
			auto &&[a, b, val] = edges[i];
			uset.merge(a, b);
			if (uset.connect(1, x * y - 1)) {
				return val;
			}
		}
		return 1;
	}
};


int main(){
    Solution solution;
	vector<vector<int>> arr{{1, 2},
							{2, 3}};

	cout << solution.swimInWater(arr);
	string a = "dsa";
}




