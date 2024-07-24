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
    ListNode* removeElements(ListNode* head, int val) {

       
        ListNode* st = new ListNode(-1);
        st->next = head;
        ListNode* n = st;
        ListNode* nxt = n->next;

        while(nxt != NULL){
             if(nxt->val == val){
                 while(nxt != NULL && nxt->val == val){
                      nxt = nxt->next;
                 }

                 if(nxt == NULL){
                    st->next = NULL;
                    break;
                 }
                 st->next = nxt;
                 st = nxt;
                 nxt = nxt->next;
             }
             else{
                nxt = nxt->next;
                st = st->next;
             }    
        }
 
        return n->next;
    }
};