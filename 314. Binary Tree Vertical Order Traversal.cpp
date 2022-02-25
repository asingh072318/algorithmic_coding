## https://leetcode.com/problems/binary-tree-vertical-order-traversal/
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> response;
        vector<int> column;
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,vector<int>> mp;
        int col = 0;
        q.push(make_pair(root,col));
        while(!q.empty()){
            pair<TreeNode*,int> curr = q.front();
            q.pop();
            root = curr.first;
            col = curr.second;
            if(root != NULL){
                if(mp[col].size()==0)
                    column.push_back(col);
                mp[col].push_back(root->val);
                q.push(make_pair(root->left,col-1));
                q.push(make_pair(root->right,col+1));   
            }
        }
        sort(column.begin(),column.end());
        for(int i=0;i<column.size();i++){
            response.push_back(mp[column[i]]);
        }
        return response;
    }
};