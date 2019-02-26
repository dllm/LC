/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (44.30%)
 * Total Accepted:    205.3K
 * Total Submissions: 459.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if (root) dfs (root, "", res);
        return res;
    }

    void dfs(TreeNode *root, string out, vector<string> &res) {
        if (!root)
            return;
        out += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(out);
        } else {
            if (root->left) dfs(root->left, out + "->", res);
            if (root->right) dfs(root->right, out + "->", res);
        }
    }
};
