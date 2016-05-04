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
    void binaryTreePaths(TreeNode* root, vector<string> &paths, string path){
        if(root == NULL) return;
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            paths.push_back(path);
        binaryTreePaths(root->left, paths, path + "->");
        binaryTreePaths(root->right, paths, path + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL) return paths;
        binaryTreePaths(root, paths, "");
        return paths;
    }
};
