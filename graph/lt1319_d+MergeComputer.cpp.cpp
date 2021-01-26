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

class DjSet {
private:
	vector<int> parent;
	int rest;
	int count;
	vector<int> sizes;
public:
	DjSet(int n) : parent(vector<int>(n)), sizes(vector<int>(n, 1)), rest(0), count(n) {

		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	void merge(int x, int y){
		int xx = find(x), yy = find(y);
		if (xx != yy) {
			if (sizes[xx] <= sizes[yy]) {
				swap(xx, yy);
			}
			parent[yy] = parent[xx];
			sizes[xx] += sizes[yy];
			count--;
		} else {
			rest++;
		}

	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	int getRest(){
		return rest;
	}
	int getCount(){
		return count;
	}

};
/*
 *
 * */
class Solution {
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		DjSet djSet(n);
		for (int i = 0; i <connections.size(); ++i) {
			djSet.merge(connections[i][0], connections[i][1]);
		}
		int need = djSet.getCount()-1;
		if (need <= djSet.getRest()) {
			return need;
		}
		return -1;
	}

};


int main(){

	Solution a = Solution();



	vector<vector<int>> v;
	a.makeConnected(4, v);

}