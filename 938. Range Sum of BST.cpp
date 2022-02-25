## 938. Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root!=NULL){
                if(root->val >= low && root->val <= high){
                    sum+=root->val;
                    q.push(root->left);
                    q.push(root->right);
                }
                else if(root->val < low)
                    q.push(root->right);
                else
                    q.push(root->left);
            }
        }
        return sum;
    }
};