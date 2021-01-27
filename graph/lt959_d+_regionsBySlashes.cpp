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
    DjSet(int n) : parent(n+1),
                           sum(0) {
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
            sum++;
            return ;
        }else{
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
        int n = grid.size();
        int m = n + 1;
        int num = m * m;
        DjSet djSet(num);

        for (int i = 0; i < num; ++i) {
            if (i / m == 0 || i % m == 0 || i % m == n || i / m == n) {
                djSet.merge(i, num);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    djSet.merge(i*m+j, (i+1)*m+j+1);
                } else if (grid[i][j] == '/') {
                    djSet.merge(i*m+j+1, (i+1)*m+j);
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