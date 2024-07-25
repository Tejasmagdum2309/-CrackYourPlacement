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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       ListNode* head = new ListNode(-1);  // Dummy node to simplify code
        ListNode* st = head;

        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                st->next = l1;  // Link to l1
                l1 = l1->next;  // Move l1 to the next node
            } else {
                st->next = l2;  // Link to l2
                l2 = l2->next;  // Move l2 to the next node
            }
            st = st->next;  // Move st to the next node in the merged list
        }

        // Link the remaining nodes
        if(l1 != NULL) {
            st->next = l1;
        } else if(l2 != NULL) {
            st->next = l2;
        }

        return head->next; 
    }
};