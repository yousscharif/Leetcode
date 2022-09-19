//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBSTHelper(nums,0,n-1);
    }
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = sortedArrayToBSTHelper(nums,low,mid-1);
        root -> right = sortedArrayToBSTHelper(nums, mid+1, high);
        return root;
    }
};