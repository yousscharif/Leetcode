
//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int>& visited) {
        if (root == nullptr) return;
        inorder(root->left, visited);
        visited.push_back(root->val);
        inorder(root->right, visited);
    }
};