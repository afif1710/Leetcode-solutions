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
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* t = head;
        while(t != NULL){
            v.push_back(t->val);
            t = t->next;
        }
    }
    
    int getRandom() {
        int size = v.size();
        int x = rand()%size;
        
        return v[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */