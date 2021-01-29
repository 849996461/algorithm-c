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
 * [0,0] -> [x-1,y-1]
 * 解决方法: 并查集
 */
class Uset {
private:
    vector<int> parent;
public:
    Uset(int n):parent(n){
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int xx = find(x), yy = find(y);
        if (xx == yy) {
            return;
        }else{
            parent[xx] = yy;
        }
    }

    bool is_connect(int x, int y){
        int xx = find(x), yy = find(y);
        return xx == yy;
    }

};
class Solution {

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int x = heights.size();
        int y = heights[0].size();
        vector<tuple<int, int, int>> edges;
        Uset uset(x * y);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int id = i * y + j;
                if (j < y - 1) {
                    edges.emplace_back(id, id + 1, abs(heights[i][j] - heights[i][j + 1]));
                }
                if (i < x - 1) {
                    edges.emplace_back(id, id + y, abs(heights[i][j] - heights[i + 1][j]));
                }
            }
        }
        sort(edges.begin(),edges.end(),[](auto &x,auto &y) {
            auto &&[x1, x2, val1] = x;
            auto &&[y1, y2, val2] = y;
            return val1 < val2;
        });

        for (auto &&[x1, x2, val]  : edges) {
            uset.merge(x1, x2);
            if (uset.is_connect(0, x * y - 1)) {
                return val;
            }
        }
        return 0;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> arr{{1, 2, 1, 1, 1},
                            {1, 2, 1, 2, 1},
                            {1, 2, 1, 2, 1},
                            {1, 2, 1, 2, 1},
                            {1, 1, 1, 2, 1}};
    cout << solution.minimumEffortPath(arr);

}




