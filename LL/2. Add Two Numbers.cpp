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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry  = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* st = ans;
        while(l1 != NULL && l2 != NULL){

            int a = l1->val + l2->val + carry;

            carry = a/10;
            int rem = a % 10;


            ListNode* n = new ListNode(rem);
            st->next = n;
            st = n;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int a = l1->val + carry;

            carry = a/10;
            int rem = a % 10;


            ListNode* n = new ListNode(rem);
            st->next = n;
            st = n;
            l1 = l1->next;
            
        }

        while(l2 != NULL){
            int a =  l2->val + carry;

            carry = a/10;
            int rem = a % 10;


            ListNode* n = new ListNode(rem);
            st->next = n;
            st = n;
            l2 = l2->next;
        }

        if(carry){
            st->next = new ListNode(carry);
        }

        return ans->next;
    }
};