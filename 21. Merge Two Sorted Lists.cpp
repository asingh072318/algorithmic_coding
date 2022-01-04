## https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    void mergeList(ListNode *lower, ListNode *higher){
        ListNode *nextHigher = higher->next;
        while(lower->next!=NULL && lower->next->val < higher->val){
            lower = lower->next;
        }
        if(lower->next == NULL){
            lower->next = higher;
            return;
        }
        else{
            higher->next = lower->next;
            lower->next = higher;
        }
        if(nextHigher == NULL)
            return;
        mergeList(higher,nextHigher);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode *lower,*higher;
        if(list1->val < list2->val){
            lower = list1;
            higher = list2;
        }
        else{
            lower = list2;
            higher = list1;
        }
        mergeList(lower,higher);
        return lower;
    }
};