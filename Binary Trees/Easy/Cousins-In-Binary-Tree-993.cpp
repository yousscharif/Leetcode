//https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundX = false, foundY = false;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->val == x) {
                    foundX = true;
                }
                else if (curr->val == y) {
                    foundY = true;
                }
                if (curr->left && curr->right){
                    set<int> cousins = {x,y};
                    set<int> s = {curr->left, curr->right};
                    if (s == cousins) {
                        return false;
                    }
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (foundX || foundY) {
                if (foundX && foundY) return true;
                return false;
            }
        }
        return false;
    }
};