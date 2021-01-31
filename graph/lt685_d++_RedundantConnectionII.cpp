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
class Uset{
private:
	vector<int> parent;

public:
	Uset(int n): parent(n){
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}

	bool merge(int x ,int y){
		int xx = find(x), yy = find(y);
		if (xx == yy) {
			return false;
		}else{
			parent[yy] = parent[xx];
			return true;
		}
	}
};

class Solution {
public:
	vector<int> getRemoveEdge(vector<vector<int>> &edges , int ignore) {
		int l = edges.size();
		Uset uset(l+1);
		for (int i = 0; i < l; ++i) {
			if (i == ignore) {
				continue;
			}
			vector<int> &edge = edges[i];
			if (!uset.merge(edge[0], edge[1])) {
				return {edge[0], edge[1]};
			}
		}
		return {-1, -1};
	}

	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int l = edges.size();
		vector<int> inDegree(l+1);
		for (int i = l-1; i >=0; --i) {
			inDegree[edges[i][1]]++;
		}
		vector<int> twoDegree;
		for (int i = l-1; i >=0; --i) {
			if(inDegree[edges[i][1]] == 2){
				twoDegree.push_back(i);
			}
		}
		if (!twoDegree.empty()) {
			auto res = getRemoveEdge(edges,twoDegree[0]);
			//存在重复
			if (res[0] == -1) {
				return edges[twoDegree[0]];
			}else{
				return edges[twoDegree[1]];
			}

		}
		return getRemoveEdge(edges, -1);

	}
};

int main(){

	Solution a = Solution();

	vector<vector<int>> arr{{2, 1},
							{3, 1},
							{4, 2},
							{1, 4}};


	auto res = a.findRedundantDirectedConnection(arr);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i];
	}

}