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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) return head;
        ListNode* pre = head;
        ListNode* nxt = head->next;

        while(nxt != NULL){
            if(pre->val == nxt->val){
                nxt = nxt->next;
            }
            else{
                pre->next = nxt;
                pre = nxt;
                nxt = nxt->next;
            }
            
        }

        pre->next = nxt;

        return head;
    }
};