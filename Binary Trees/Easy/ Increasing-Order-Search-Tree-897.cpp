//https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0); // dummy node
        prev = head;
        increasingBSTHelper(root);
        return head->right;
    }
    void increasingBSTHelper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        increasingBSTHelper(root->left);
        root->left = nullptr;
        prev->right = root;
        prev = root;
        increasingBSTHelper(root->right);
    }   
};