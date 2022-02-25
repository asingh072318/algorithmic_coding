## https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> response;
        map<int,vector<pair<int,int>>>  mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        int col = 0,row=0;
        q.push(make_pair(root,make_pair(col,row)));
        while(!q.empty()){
            root = q.front().first;
            col = q.front().second.first;
            row = q.front().second.second;
            q.pop();
            if(root!=NULL){
                mp[col].push_back(make_pair(row,root->val));
                q.push(make_pair(root->left,make_pair(col-1,row+1)));
                q.push(make_pair(root->right,make_pair(col+1,row+1)));   
            }
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            vector<pair<int,int>> c = mp[it->first];
            sort(c.begin(),c.end());
            vector<int> cp;
            for(int i=0;i<c.size();i++)
                cp.push_back(c[i].second);
            response.push_back(cp);
        }
        return response;
    }
};