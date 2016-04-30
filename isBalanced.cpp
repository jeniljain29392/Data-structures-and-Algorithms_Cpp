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
    bool _isBalanced(TreeNode* root, int& height) {
        if(root == NULL) return true;
        
        int left_h = 0, right_h = 0;
        if(!_isBalanced(root->left, left_h)) return false;
        if(!_isBalanced(root->right, right_h)) return false;
        if(abs(left_h - right_h) > 1) return false;
        
        height = max(left_h, right_h) + 1;
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return _isBalanced(root, height);
    }
};
