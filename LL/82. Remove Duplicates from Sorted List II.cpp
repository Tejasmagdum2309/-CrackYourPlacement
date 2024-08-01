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
        ListNode* l1 = new ListNode(-1000);
        l1->next = head;
        head = l1;

        l1 = l1->next;
        
        ListNode* pre = head;int cnt = 0;int d = 0;
        while(l1 != NULL){
             if(pre->next->val == l1->val){
                  cnt++;
                  l1 = l1->next;
             }
             else{
                  if(cnt > 1){
                     pre->next = l1;
                  }
                  else{
                    pre = pre->next;
                  }
                  cnt = 0;
             }

        }
        if(cnt > 1) pre -> next = l1;
        return head->next;;



    }
};