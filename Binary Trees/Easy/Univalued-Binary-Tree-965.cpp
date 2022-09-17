//https://leetcode.com/problems/univalued-binary-tree/
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
    bool isUnivalTree(TreeNode* root) {
        int value = root ? root->val : -1;
        return isUnivalTreeHelper(root, value);
    }
    bool isUnivalTreeHelper(TreeNode* root, int currValue) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != currValue) {
            return false;
        }
        bool leftCall = isUnivalTreeHelper(root->left, currValue);
        bool rightCall = isUnivalTreeHelper(root->right, currValue);
        return leftCall && rightCall;
    }
};