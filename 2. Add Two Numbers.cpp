## https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* response = new ListNode();
        ListNode* ptr = response;
        int carry = 0;
        while(l1!=NULL || l2 != NULL){
            if(l1!=NULL && l2!=NULL){
                int newVal = carry + l1->val + l2->val;
                carry=0;
                if(newVal < 10)
                    ptr->val = newVal;
                else{
                    ptr->val = newVal-10;
                    carry = newVal/10;
                }
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1==NULL && l2!=NULL){
                int newVal = carry + l2->val;
                carry=0;
                if(newVal < 10)
                    ptr->val = newVal;
                else{
                    ptr->val = newVal-10;
                    carry = newVal/10;
                }
                l2=l2->next;
            }
            else if(l1!=NULL && l2==NULL){
                int newVal = carry + l1->val;
                carry=0;
                if(newVal < 10)
                    ptr->val = newVal;
                else{
                    ptr->val = newVal-10;
                    carry = newVal/10;
                }
                l1=l1->next;
            }
            if(carry!=0 || l1!=NULL || l2!=NULL){
                ptr->next = new ListNode();
                ptr=ptr->next;   
            }
        }
        if(carry!=0)
            ptr->val = carry;
        return response;
    }
};