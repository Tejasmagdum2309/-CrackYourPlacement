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
   
    ListNode* sortll(ListNode* l1,ListNode* l2){

        ListNode* head = new ListNode(-1);
        ListNode* curr= head;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }

        while(l1 != NULL){
            curr->next = l1;

            l1 = l1->next;
            curr = curr->next;
        }

        while(l2 != NULL){
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        
        return head->next;
    }
    
    ListNode* rec(ListNode* h){
        if(h == NULL || h->next == NULL) return h;
        ListNode* s = h;
        ListNode* f = h;

        while(f->next != NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        
        f = s->next;
        s->next = NULL;
        s = h;
        

        ListNode* left = rec(s);
        ListNode* right = rec(f);

        ListNode* ans = sortll(left,right);
        return ans;

    }

    ListNode* sortList(ListNode* head) {
         
       return rec(head);
    }
};