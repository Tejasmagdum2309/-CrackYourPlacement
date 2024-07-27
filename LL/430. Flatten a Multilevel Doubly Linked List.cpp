/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   
    void recursion(Node* h){
        if(h == NULL) return ;
        
        if(h->child != NULL){
           Node* nxt = NULL;
           nxt = h->next;
           if(nxt != NULL)nxt->prev = NULL;
           h->next = NULL;
           h->next = h->child;
           h->child->prev = h;
           h->child = NULL;
           

           recursion(h->next);

           while(h->next != NULL){
                h = h->next;
           }
           h->next = nxt;

           if(nxt!=NULL) nxt -> prev = h;


        }
        else{
           
            h = h->next;
            recursion(h);
           
        }


    }
     
    Node* flatten(Node* head) {
        
        recursion(head);
        return head;
    }
};