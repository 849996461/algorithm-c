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
 * 从 [0,0] -> [x-1,y-1]
 * 每个格子有不同的海拔 , 每天海拔都-1 , 多多少起点和终点连通
 */
class Uset{
private:
	vector<int> parent;

public:
	Uset(int n):parent(n){
		for (int i = 0; i < n; ++i) {
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
		int y = grid[0].size();
		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				int id = i * y + j;
				if (i < x - 1) {
					edges.emplace_back(id, id + y, max(grid[i][j],grid[i+1][j]));
				}
				if (j < y - 1) {
					edges.emplace_back(id, id + 1, max(grid[i][j], grid[i][j + 1]));
				}
			}
		}
		sort(edges.begin(), edges.end(), [](auto &x, auto &y) {
			auto &&[x1, x2, val1] = x;
			auto &&[y1, y2, val2] = y;
			return val1 < val2;
		});
		Uset uset(x * y);
		for (int i = 0; i < edges.size(); ++i) {
			auto &&[a, b, val] = edges[i];
			uset.merge(a, b);
			if (uset.connect(0, x * y - 1)) {
				return val;
			}
		}
		return 0;
	}
};


int main(){
    Solution solution;
	vector<vector<int>> arr{{0, 2},
							{1, 3}};
	cout << solution.swimInWater(arr);

}




