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
        // Creating a new duplicate Node right after each Node
        while(curr){
            Node* nxt = curr->next;                  //B
            curr->next = new Node(curr->val);        //A -> x -> B, inseting new node between A and B
            curr->next->next = nxt;                  // A -> B
            curr = nxt;                              // moving curr from A to B
        }
   
        
        curr = head;
        // Assigning random pointers to the newly created nodes
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
        // Connecting the given Nodes to each other and also the newly created Nodes to each other
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
















