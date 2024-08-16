/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* temp = root,*last =  root,*r = root;

        while(r!= NULL){
            if(r->left != NULL){

               temp ->next = r->left;
               temp = temp->next;
            }
            
            if(r->right != NULL){

               temp ->next = r->right;
               temp = temp->next;
            }
            
            if(last == r){
                r = last->next;
                last->next = NULL;
                last = temp;

            }
            else{
                r = r->next;
            }

        }
        return root;
    }
};