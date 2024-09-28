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
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        ListNode* small = new ListNode();
        ListNode* large = new ListNode();
        
        ListNode* smlptr = small;
        ListNode* lrgptr = large;
        
        while(head){
            if(head->val < x){
                smlptr->next = head;
                smlptr = smlptr->next;
            }else{
                lrgptr->next = head;
                lrgptr = lrgptr->next;    
            }
            head = head->next;
        }
        smlptr->next = large->next;
        lrgptr->next = NULL;
        
        return small->next;       
    }
};