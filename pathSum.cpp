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
    vector<vector<int>> allPath;
    void _pathSum(TreeNode* root, int sum, vector<int> path, int height) {
        if(root==NULL)
            return;
            
        path.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
            int sum_path = 0;
            for(std::vector<int>::iterator it = path.begin(); it != path.end(); it++){
                sum_path += *it;
                cout<<*it;
            }
            cout<<endl<<sum_path<<endl;
            if(sum_path == sum)
                allPath.push_back(path);
        }
        else{
            _pathSum(root->left, sum, path, height+1);
            _pathSum(root->right, sum, path, height+1);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if(root==NULL)
            return allPath;
            
        _pathSum(root, sum, path, 0);
        return allPath;
    }
};
