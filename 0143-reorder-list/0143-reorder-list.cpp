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
    
    ListNode* revList(ListNode* h){
        ListNode* prev = NULL;
        ListNode* curr = h;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = revList(slow);
        
        ListNode* curr = head;
        while(rev->next != NULL){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = rev->next;
            
            curr->next = rev;
            rev->next = temp1;
            curr = temp1;
            rev = temp2;
        }
        
    }
};
















