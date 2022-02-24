## https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
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
    TreeNode* lc(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode* lca1 = lc(root->left,p,q);
        TreeNode* lca2 = lc(root->right,p,q);
        if(lca1 != NULL && lca2 != NULL)
            return root;
        if(lca1!=NULL)
            return lca1;
        return lca2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size() == 1)
              return nodes[0];
        TreeNode *p = nodes[0];
        TreeNode *q = nodes[1];
        TreeNode *lca = lc(root,p,q);
        for(int i=2;i<nodes.size();i++){
            lca = lc(root,lca,nodes[i]);
        }
        return lca;
    }
};