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
class BSTIterator {
public:
    vector<TreeNode*> nodes;
    int start = 0;
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if(!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    BSTIterator(TreeNode* root) {
        inorder(root, nodes);
    }
    
    int next() {
        int temp = nodes[start]->val;
        start++;
        return temp;
    }
    
    bool hasNext() {
        if(start < nodes.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */