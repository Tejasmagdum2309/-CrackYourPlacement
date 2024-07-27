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
    
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while(f-> next != NULL && f->next->next != NULL){
             s = s->next;
             f = f->next->next;
        }

        
        
        ListNode* r = s->next;
        s->next = NULL;

        r = rev(r);

        while(r != NULL && head != NULL){
             if(r->val != head->val ) return false;
             r = r->next;
             head = head->next;
        }
        return true;

    }
};