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
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 解法: 边缘 O dfs
 *
 */
class Solution {
public:

    void change(int i, int j, vector<vector<char>> &board) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O') {
            board[i][j] = 'Z';
            change(i+1, j, board);
            change(i, j+1, board);
            change(i-1, j, board);
            change(i, j-1, board);
        }

	}

	void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int x = board.size();
        int y = board[0].size();
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (i == 0 || i == x - 1 || j == 0 || j == y - 1 ) {
                    change(i, j, board);
                }
            }
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }

	}


};


int main(){

	Solution a = Solution();
	vector<vector<char>> arr = {{'O', 'O', 'O', 'O', 'X', 'X'},
								{'O', 'O', 'O', 'O', 'O', 'O'},
								{'O', 'X', 'O', 'X', 'O', 'O'},
								{'O', 'X', 'O', 'O', 'X', 'O'},
								{'O', 'X', 'O', 'X', 'O', 'O'},
								{'O', 'X', 'O', 'O', 'O', 'O'}};



	a.solve(arr);

	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			cout << arr[i][j] << ' ';

		}
		cout << endl;
	}



}