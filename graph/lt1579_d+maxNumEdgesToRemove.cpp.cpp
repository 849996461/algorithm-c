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
 * remove Max edges to keep Alice and  Bob can also traverse all graph
 * 解法: 并查集
 */
class Uset {
private:
	vector<int> parent;
	int need;
public:
	Uset(int n) : parent(vector<int>(n+1)), need(n)  {

		for (int i = 0; i < n+1; ++i) {
			parent[i] = i;
		}
	}

	bool merge(int x, int y){
		int xx = find(x), yy = find(y);
		if (xx != yy) {
            parent[xx] = yy;
            need--;
            return true;
		} else {
			return false;
		}
	}

	int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
	}

	int getNeed(){
		return need;
	}

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        Uset aset(n), bset(n);
        for (vector<int> &edge :edges) {
            if (edge[0] == 3) {
                if (!aset.merge(edge[1], edge[2])){
                    ans++;
                }else{
                    bset.merge(edge[1], edge[2]);
                }
            }
        }
        for (vector<int> &edge :edges) {
            if (edge[0] == 1) {
                if (!aset.merge(edge[1], edge[2])){
                    ans++;
                }
            }
            else if (edge[0] == 2) {
                if (!bset.merge(edge[1], edge[2])){
                    ans++;
                }
            }
        }
        if (aset.getNeed() > 1 || bset.getNeed() > 1) {
            return -1;
        }
        return ans;

    }

};


int main(){

	Solution a = Solution();
    vector<vector<int>> v = {{3, 1, 2},
                             {3, 2, 3},
                             {1, 1, 3},
                             {1, 2, 4},
                             {1, 1, 2},
                             {2, 3, 4}};


    cout << a.maxNumEdgesToRemove(4, v);





}