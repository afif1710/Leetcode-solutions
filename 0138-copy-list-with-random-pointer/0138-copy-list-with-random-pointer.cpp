/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        Node* curr = head;
        // Creating a new duplicate Node right after each
        while(curr){
            Node* nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;
            curr = nxt;
        }
        
        curr = head;
        // Assigning random pointer
        while(curr){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        curr = head;
        Node* newhead = head->next;
        Node* newcurr = newhead;
        
        while(curr && newcurr){
            if(curr->next == NULL){
                curr->next = NULL;
            }else{
                curr->next = curr->next->next;
            }
            if(newcurr->next == NULL){
                newcurr->next = NULL;
            }else{
                newcurr->next = newcurr->next->next;
            }
            //curr->next = curr->next == NULL ? NULL: curr->next->next;
            //newcurr->next = newcurr->next == NULL ? NULL: newcurr->next->next;
            curr = curr->next;
            newcurr = newcurr->next;
        }
        
        
        
        return newhead;
        
        
        
        
    }
};
















