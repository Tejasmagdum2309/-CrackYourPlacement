//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    Node* rev(Node* l){
        Node* pre = NULL;
        Node* curr = l;
        
        while(curr != NULL){
            Node* n = curr->next;
            curr->next = pre;
            pre = curr;
            curr = n;
        }
        
        return pre;
    }
    void reorderList(Node* head) {
        // Your code here
        
        Node* s = head;
        Node* f = head;
        
        while(f->next != NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        
        f = s->next;
        s->next = NULL;
        s = head;
        f = rev(f);
        
        Node* curr = s;
        int l = 1;
        while(f != NULL && s != NULL){
            if(l){
            l = 0;
            s = s->next;
            curr->next = f;
            curr = curr->next;
                
            }
            else{
                l = 1;
                f = f->next;
                curr->next = s;
                curr = curr->next;
            }
            
        }
        
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends