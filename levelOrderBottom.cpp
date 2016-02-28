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
private:
    void _levelOrderBottom(TreeNode* root, int height, vector<vector<int>> &levels) {
        if(root == NULL)
            return;
        else{
            levels[height-1].push_back(root->val);
            _levelOrderBottom(root->left, height-1, levels);
            _levelOrderBottom(root->right, height-1, levels);
        }
    }
    
public:
    int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        else{
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
            
            if(lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = maxDepth(root);
        vector<vector<int>> levels(height);
        _levelOrderBottom(root, height, levels);
        return levels;
    }
};
