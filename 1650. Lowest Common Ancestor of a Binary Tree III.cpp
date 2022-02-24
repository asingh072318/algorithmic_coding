## https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> path1,path2;
        Node *ptr1,*ptr2;
        ptr1=p;
        ptr2=q;
        while(ptr1!=NULL){
            path1.push_back(ptr1);
            ptr1=ptr1->parent;
        }
        while(ptr2!=NULL){
            path2.push_back(ptr2);
            ptr2=ptr2->parent;
        }
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        int i = 0;
        while(i<path1.size() && i<path2.size() && path1[i]==path2[i])
            i++;
        return path1[i-1];
    }
};