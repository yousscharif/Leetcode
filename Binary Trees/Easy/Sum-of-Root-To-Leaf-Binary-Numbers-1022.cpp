//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafHelper(root,0);
    }

    int sumRootToLeafHelper(TreeNode* root, int currNumber) {
        if (root == nullptr) {
            return 0;
        }
        currNumber = currNumber << 1 | root->val;
        if (isLeaf(root)) {
            return currNumber;
        }
        int leftCall = sumRootToLeafHelper(root->left, currNumber);
        int rightCall = sumRootToLeafHelper(root->right, currNumber);
        return leftCall + rightCall;
    }

    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};