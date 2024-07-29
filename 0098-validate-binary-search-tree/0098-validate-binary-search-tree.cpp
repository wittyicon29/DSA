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
    bool isValidBST(TreeNode* root) {
        return validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }

private:
    bool validate(TreeNode* node, long long low, long long high) {
        if (!node) {
            return true; // Base case: an empty node is valid
        }
        if (node->val <= low || node->val >= high) {
            return false; // Current node's value must be within the range
        }
        // Recursively validate the left and right subtrees
        return validate(node->left, low, node->val) && validate(node->right, node->val, high);
    }
};