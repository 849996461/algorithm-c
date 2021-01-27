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
    int sum ;


public:
    DjSet(int x, int y) : parent(x * y * 4),
                           sum(x * y * 4) {
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

    }
    int getSum(){
        return sum;
    }


    void merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) {
            return ;
        }else{
            sum--;
            parent[yy] = parent[xx];
        }

    }

    int find(int s) {
        return (s == parent[s]) ? s : (parent[s] = find(parent[s]));
    }

};

/**
 * 并查集思路:
 * 1.以面合并 , res = sum - merge_success
 * 2.以点合并 , res = 1 + merge_failed
 */
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        auto idx = [&](int i,int j , int k) -> int { return i * y * 4 + j * 4 + k; };

        DjSet djSet(x,y);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int p0 = idx(i, j, 0);
                if (grid[i][j] == ' '){
                    djSet.merge(p0, p0+1);
                    djSet.merge(p0+1, p0+2);
                    djSet.merge(p0+2, p0+3);
                }else if (grid[i][j] == '\\'){
                    djSet.merge(p0+1, p0+2);
                    djSet.merge(p0, p0+3);
                }else if (grid[i][j] == '/') {
                    djSet.merge(p0, p0+1);
                    djSet.merge(p0+2, p0+3);
                }
                if (j < grid[0].size()-1) {
                    djSet.merge(p0+2, p0+4);
                }
                if (i < grid.size() - 1) {
                    djSet.merge(p0 + 3, idx(i + 1, j, 1));
                }
            }


        }
        return djSet.getSum();
    }
};


int main(){



    Solution a = Solution();
    vector<string> parent = {" /","/ "};

    cout << a.regionsBySlashes(parent);


}