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
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = NULL;
        while(curr != NULL){
           ListNode* n = curr->next;
           curr->next = pre;
           pre = curr;
           curr = n;


        }
        return pre;
    }
    
    int getDecimalValue(ListNode* head) {
        
        ListNode* nhead = reverse(head);

        int i = 0;
        int ans = 0;

        while(nhead != NULL){
             ans+=(nhead->val * (1 << i));
             i++;
             nhead = nhead->next;
        } 
        return ans;
    }
};