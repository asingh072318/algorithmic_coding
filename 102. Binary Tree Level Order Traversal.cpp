## https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        int row=0;
        q.push(make_pair(row,root));
        vector<vector<int>> response;
        map<int,vector<int>> mp;
        while(!q.empty()){
            root = q.front().second;
            row = q.front().first;
            q.pop();
            if(root!=NULL){
                mp[row].push_back(root->val);
                q.push(make_pair(row+1,root->left));
                q.push(make_pair(row+1,root->right));
            }
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            response.push_back(mp[it->first]);
        }
        return response;
    }
};