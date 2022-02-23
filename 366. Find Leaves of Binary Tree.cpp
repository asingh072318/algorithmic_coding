## https://leetcode.com/problems/find-leaves-of-binary-tree/
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
    
    int getHeight(TreeNode* root, vector<pair<int,int>>& height){
        if(root == NULL)
            return -1;
        int lheight = getHeight(root->left,height);
        int rheight = getHeight(root->right,height);
        int cheight = 1 + max(lheight,rheight);
        height.push_back(make_pair(cheight,root->val));
        return cheight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<pair<int,int>> height;
        getHeight(root,height);
        sort(height.begin(),height.end());
        vector<vector<int>> response;
        vector<int> curr;
        curr.push_back(height[0].second);
        for(int i=1;i<height.size();i++){
            if(height[i].first != height[i-1].first){
                response.push_back(curr);
                curr.clear();
            }
            curr.push_back(height[i].second);
        }
        response.push_back(curr);
        return response;
    }
};


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
    
    int getHeight(TreeNode* root, vector<vector<int>>& response){
        if(root == NULL)
            return -1;
        int lheight = getHeight(root->left,response);
        int rheight = getHeight(root->right,response);
        int cheight = 1 + max(lheight,rheight);
        if(response.size() == cheight)
            response.push_back({});
        response[cheight].push_back(root->val);
        return cheight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> response;
        getHeight(root,response);
        return response;
    }
};