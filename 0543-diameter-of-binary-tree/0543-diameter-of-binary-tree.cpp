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
    int height(TreeNode* node, int& diameter) {
        if(!node) {
            return 0;
        }

        int leftH = height(node->left, diameter);
        int rightH = height(node->right, diameter);

        diameter = max(diameter, leftH + rightH);

        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int diameter = 0;

        height(root, diameter);
        return diameter;
    }
};