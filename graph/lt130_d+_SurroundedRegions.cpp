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

	char check(int x, int y, int i, int j,vector<vector<char>> &board) {
		if (i < 0 || j < 0 || i > x - 1 || j > y - 1) {
			return 'X';
		}

		if (board[i][j] == 'X') {
			return 'X';
		}
		else if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
			board[i][j] = 'Z';
		}else{
			if (check(x, y, i, j + 1, board) == 'Z'
				|| check(x, y, i + 1, j, board) == 'Z'
				|| board[i - 1][j] == 'Z'
				|| board[i][j - 1] == 'Z'
					) {
				board[i][j] = 'Z';
			} else {
				board[i][j] = 'X';
			}
		}
		return board[i][j];
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty()) {
			return ;
		}
		int x = board.size();
		int y = board[0].size();
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				check(x, y, i, j,board);
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