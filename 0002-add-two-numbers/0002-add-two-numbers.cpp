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
    ListNode* revlist(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* dln(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
        return head;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revlist(l1);
        l2 = revlist(l2);

        stack<int>s1;
        stack<int>s2;
        int sum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;

        }
        
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
                
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            ans->val = sum % 10;         
            carry = sum/10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }
        
        ListNode* ta = revlist(ans);
        if(carry == 0){
            dln(ta);
        }
        //return carry == 0 ? ta : ta->next;
        return ta;
    }
};
