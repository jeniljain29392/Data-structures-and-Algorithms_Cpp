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
    int _minDepth(TreeNode* root, int height){
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return height + 1;
        return min(_minDepth(root->left, height + 1), _minDepth(root->right, height + 1));
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return _minDepth(root, 0);
    }
};
