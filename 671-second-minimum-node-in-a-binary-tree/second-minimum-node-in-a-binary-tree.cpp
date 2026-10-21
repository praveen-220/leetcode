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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)
            return -1;

        int ans = -1;

        if (root->left != NULL) {
            int left = findSecondMinimumValue(root->left);
            int right = findSecondMinimumValue(root->right);

            if (left != -1)
                ans = left;

            if (right != -1 && (ans == -1 || right < ans))
                ans = right;

            if (root->left->val != root->val)
                ans = (ans == -1) ? root->left->val: min(ans, root->left->val);

            if (root->right->val != root->val)
                ans = (ans == -1) ? root->right->val: min(ans, root->right->val);
        }

        return ans;
    }
};