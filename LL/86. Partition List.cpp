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
    ListNode* partition(ListNode* A, int B) {
    ListNode* t = A;ListNode* n = new ListNode(0);
    ListNode* nc = n;
    while(t != NULL){
        if(t->val < B){
            nc->next = new ListNode(t->val);
            nc = nc->next;
        }
        t = t->next;
    }

    t = A;
    while(t != NULL){
        if(t->val >= B){
            nc->next = new ListNode(t->val);
            nc = nc->next;
        }
        t = t->next;
    }

    return n->next;
    }
};