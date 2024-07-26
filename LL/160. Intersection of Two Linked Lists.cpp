/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while(l1 != NULL && l2 != NULL){
             l1 = l1->next;
             l2 = l2->next;
        }

        int l1cnt = 0;int l2cnt = 0;
        while(l1 != NULL){
             l1cnt++;
             l1 = l1->next;
        }

        while(l2 != NULL){
            l2cnt++;
            l2 = l2->next;
        }
           
           l1 = headA;
           l2 = headB;
       
           while(l1cnt != 0){
               l1 = l1->next;
               l1cnt--;

           }
           
           while(l2cnt != 0){
               l2 = l2->next;
               l2cnt--;
           }

           while(l1 != NULL){
                if(l1 == l2) return l1;
                l1 = l1->next;
                l2 = l2->next;
           }
           
           


        return NULL;

        
    }
};