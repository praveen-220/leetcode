/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr)
            return;

        // Choose the current node
        path.push_back(root->val);
        targetSum -= root->val;

        // Check whether this is a valid root-to-leaf path
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0)
                ans.push_back(path);
        } else {
            solve(root->left, targetSum, path);
            solve(root->right, targetSum, path);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};