//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    TreeNode* prev;
    int minDiff = 1e9;

    int minDiffInBST(TreeNode* root) {
        prev = new TreeNode(1e9);
        inOrder(root);
        return minDiff;    
    }
    
    void inOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left);
        minDiff = min(minDiff, abs(root->val - prev->val));
        prev = root;
        inOrder(root->right);
    }
};