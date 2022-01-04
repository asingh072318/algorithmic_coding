## https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q1,q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                Node* n1 = q1.front();
                q1.pop();
                if(!q1.empty()){
                  n1->next = q1.front();
                }else{
                  n1->next = NULL;
                }
                if(n1->left != NULL)
                {
                    q2.push(n1->left);
                }
                if(n1->right != NULL){
                    q2.push(n1->right);
                }
            }
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        return root;
    }
};