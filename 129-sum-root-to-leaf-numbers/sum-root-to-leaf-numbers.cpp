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
    int solve(TreeNode* root, int current) {
        if (root == nullptr)
            return 0;

        current = current * 10 + root->val;

        // If leaf node, return the number formed
        if (root->left == nullptr && root->right == nullptr)
            return current;

        // Sum the numbers from left and right subtrees
        return solve(root->left, current) +
               solve(root->right, current);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};