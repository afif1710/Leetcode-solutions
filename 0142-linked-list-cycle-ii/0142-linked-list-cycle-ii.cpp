/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }

        }
        if(fast == slow){
            ListNode* nxt = head;
        
            while(nxt != slow){
                nxt = nxt->next;
                slow = slow->next;
            }
            return nxt;  
        }
        else{
            return NULL;
        }
        
           
    }
};