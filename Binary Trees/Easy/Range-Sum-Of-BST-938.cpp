//https://leetcode.com/problems/range-sum-of-bst/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int leftCall = rangeSumBST(root->left, low, high);
        int rightCall = rangeSumBST(root->right, low, high);
        int rangeSum = leftCall + rightCall;
        if (root->val >= low && root->val <= high) {
            rangeSum += root->val;
        }
        return rangeSum;
    }
};