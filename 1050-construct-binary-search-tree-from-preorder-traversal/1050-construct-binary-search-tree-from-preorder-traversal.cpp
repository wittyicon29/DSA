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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        std::stack<TreeNode*> stack;
        stack.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = nullptr;

            // While there's a stack and the current value is greater than the top of the stack
            while (!stack.empty() && preorder[i] > stack.top()->val) {
                node = stack.top();
                stack.pop();
            }

            // Create a new node
            TreeNode* newNode = new TreeNode(preorder[i]);

            // If we found a node, it means the current value is its right child
            if (node) {
                node->right = newNode;
            } else {
                // Otherwise, it is the left child of the last node in the stack
                stack.top()->left = newNode;
            }

            // Push the new node onto the stack
            stack.push(newNode);
        }

        return root;
    }
};