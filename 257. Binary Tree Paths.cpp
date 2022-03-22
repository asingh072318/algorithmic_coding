## https://leetcode.com/problems/binary-tree-paths/
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
    
    void fPaths(TreeNode* root,vector<string>& paths,string p){
        p=p+"->"+to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            p.erase(0,2);
            paths.push_back(p);
        }
        else{
            if(root->left)
                fPaths(root->left,paths,p);
            if(root->right)
                fPaths(root->right,paths,p);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        fPaths(root,paths,"");
        return paths;
    }
};