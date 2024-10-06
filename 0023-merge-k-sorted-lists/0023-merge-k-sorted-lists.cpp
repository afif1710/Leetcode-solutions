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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }else if(!l1 && !l2){
            return NULL;
        }
        
        if(l1->val <= l2->val){
            l1->next = mergeList(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeList(l2->next, l1);
            return l2;
        }
        
        
    }
    ListNode* partitionLists(int s, int e, vector<ListNode*>& lists){
        int size = lists.size();
        ListNode* li1;
        ListNode* li2;

        int mid = (s+e)/2;
        if(s == e){
            return lists[s];
        }
        else if(s<e){
            li1 = partitionLists(s, mid, lists);
            li2 = partitionLists(mid+1, e, lists);
        }else{
            return NULL;
        }
        
        return mergeList(li1, li2);
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = 0;
        int e = lists.size()-1;
        ListNode* ans = partitionLists(s, e, lists);
        return ans;
        
    }
};

















