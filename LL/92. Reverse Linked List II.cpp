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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head->next == NULL){
            return head;
        }

        int cnt = 1;

        if(left == 1){
           ListNode* leftnode = head;
           ListNode* pre = head;
           ListNode* temp = pre->next;

           while(cnt != right){
               ListNode* nnxt = temp->next;
               temp->next = pre;
               pre = temp;
               temp = nnxt;
               cnt++;
           }
           ListNode* rightnode = pre;
           leftnode->next = temp;
           head = rightnode;
           
        }
        else{
            ListNode* pp = head;
            while(cnt != left-1){
                 pp = pp->next;
                 cnt++;
            }

            cnt++;
            ListNode* leftnode = pp->next;
            ListNode* pre = pp->next;
            ListNode* temp = pre->next;
            while(cnt != right){
                 ListNode* nnxt = temp->next;
                 temp->next = pre;
                 pre = temp;
                 temp = nnxt;
                 cnt++;
            }

            ListNode* rightnode = pre;
            pp->next = rightnode;
            leftnode->next = temp;
            
        }

        return head;

    }
};