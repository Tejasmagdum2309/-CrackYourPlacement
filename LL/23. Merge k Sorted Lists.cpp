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

    struct comp{
        bool operator() (ListNode* l1,ListNode* l2){
             return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>,comp> pq;
        
        for(auto l : lists){
        if(l != NULL)pq.push(l);
           
        }

        ListNode* h = new ListNode(-1);
        ListNode* curr = h;

        while(!pq.empty()){
            ListNode* sm = pq.top();
            pq.pop();
            curr->next = sm;
            curr = curr->next;
            if(sm->next != NULL){
                pq.push(sm->next);
            }
        }

        return h->next;

    }
};