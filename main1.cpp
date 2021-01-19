#include <iostream>
#include "unordered_set"
#include "set"
#include "math.h"
#include "vector"
#include "list"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root){
            return res;
        }
        list<TreeNode *> list = {root};
        bool order = true;
        while (!list.empty()) {
            int size = list.size();
            vector<int> row;
            for (int i = 0; i < size; ++i) {
                TreeNode node = *list.back();
                list.pop_back();

                if (order) {
                    if (node.left) {
                        list.push_back(node.left);
                    }
                    if (node.right) {
                        list.push_back(node.right);
                    }
                }
                else{
                    if (node.right) {
                        list.push_back(node.right);
                    }
                    if (node.left) {
                        list.push_back(node.left);
                    }
                }
                row.push_back(node.val);
            }
            order = !order;
            res.push_back(row);
        }
        return res;
    }

};

int main() {
    Solution a = Solution();
//    cout << a.zigzagLevelOrder();
//    unordered_set<int> set = {1, 2, 3, 4, 5};
//    cout << max(1,(int)set.size());

}
