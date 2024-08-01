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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL || k == 1){
            return head;
        }

        int len = 0;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
              fast = fast->next->next;
              len+=2;
        }
        if(fast == NULL){
            len;
        }
        else{
            len++;
        }
         cout<<len<<" ";
        int loopcnt = len/k;
        
        ListNode* st = head;
        ListNode* pre = head;
        ListNode* temp = pre->next;
        bool t = true;
        int cnt = 1;
        while(loopcnt){
          
          while(cnt != k){
              ListNode* nnxt = temp->next;
              temp->next = pre;
              pre = temp;
              temp = nnxt;
              cnt++;
          }
          cnt =1;
          if(t){
              t = false;
              st->next = temp;
              head = pre;
          }
          else{
              ListNode* st1 = st->next;
              st->next = pre;
              st1->next = temp;
              st = st1;
          }

          if(temp == NULL){
              break;
          }
          else{
              pre = temp;
              temp = temp->next;
          }
          loopcnt--;

        }
        
        return head;
    }
};