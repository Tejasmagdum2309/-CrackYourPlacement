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
    
     ListNode* rev(ListNode* h){
         ListNode* pre = NULL;
         ListNode* curr = h;

         while(curr != NULL){
              ListNode* n = curr->next;
              curr->next = pre;
              pre = curr;
              curr = n;
         }

         return pre;
    }

    void reorderList(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while(f-> next != NULL && f->next->next != NULL){
             s = s->next;
             f = f->next->next;
        }

        
        
        ListNode* r = s->next;
        s->next = NULL;

        r = rev(r);

        ListNode* st = head;
        bool t = true;

        ListNode* l1 = head;
        ListNode* l2 = r;

        while(!(l1 == NULL && l2 == NULL)){
            if(t){
               t = false;
               l1 = l1->next;
               st->next = l2;
               st = st->next;
            }
            else{
               t = true;
               l2 = l2->next;
               st->next = l1;
               st = st->next;
            }
        }

        
        
        // return head;
    }
};