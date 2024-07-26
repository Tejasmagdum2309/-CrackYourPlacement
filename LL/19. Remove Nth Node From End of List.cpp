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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int mid = 1;
        ListNode* slow = head; ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            mid++;
            slow = slow->next;
            fast = fast->next->next;
        }
        int len  = 0;
        if(fast != NULL){
            len = mid * 2 -1;
        }
        else{
            len = mid * 2 -2;
        } 

        int findn = len - n + 1;
        if(findn == 1){
            head = head->next;
            return head;
        }
        if(findn-1 < mid){
            int cnt = 1;
            ListNode* temp = head;
            while(cnt != findn-1){
                cnt++;
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        else{
            // int cnt = 1;
            ListNode* temp = slow;
            while(mid != findn-1){
                mid++;
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};