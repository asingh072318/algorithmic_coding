## https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode* lca1 = lca(root->left,p,q);
        TreeNode* lca2 = lca(root->right,p,q);
        if(lca1!=NULL && lca2!= NULL)
            return root;
        if(lca1!=NULL)
            return lca1;
        return lca2;
    }
    void height(TreeNode *root,vector<pair<int,TreeNode*>>& deepest,int h){
        if(root == NULL)
            return;
        deepest.push_back(make_pair(h,root));
        height(root->left,deepest,h+1);
        height(root->right,deepest,h+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<pair<int,TreeNode*>> deepest;
        height(root,deepest,0);
        int n = deepest.size();
        if(deepest.size()==1)
            return root;
        sort(deepest.begin(),deepest.end());
        if(deepest[n-1].first != deepest[n-2].first)
            return deepest[n-1].second;
        int maxd = deepest[n-1].first;
        vector<TreeNode*> nodes;
        for(int i=0;i<deepest.size();i++){
            if(deepest[i].first == maxd)
                nodes.push_back(deepest[i].second);
        }
        TreeNode *p = nodes[0];
        TreeNode *q = nodes[1];
        TreeNode *lc = lca(root,p,q);
        for(int i = 2;i<nodes.size();i++){
            lc = lca(root,lc,nodes[i]); 
        }
        return lc;
    }
};