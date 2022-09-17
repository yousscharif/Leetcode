//https://leetcode.com/problems/leaf-similar-trees/
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1, leafValues2;
        preOrder(root1, leafValues1);
        preOrder(root2, leafValues2);
        return leafValues1 == leafValues2;
    }
    
    void preOrder(TreeNode* root, vector<int>& leafValues) {
        if (root == nullptr) return;
        if (isLeaf(root)) {
            leafValues.push_back(root->val);
        }
        preOrder(root->left, leafValues);
        preOrder(root->right, leafValues);
    }

    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};