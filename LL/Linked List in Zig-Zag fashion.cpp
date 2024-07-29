//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        
         Node *ptr = head ;
        int i=0,temp ;
        while(ptr)
        {
            if(i==0)
            {
                if(ptr->next && ptr->data>ptr->next->data)
                {
                    temp = ptr->data ;
                    ptr->data = ptr->next->data ;
                    ptr->next->data = temp ;
                }
                i=1 ;
            }
            else
            {
                if(ptr->next && ptr->data<ptr->next->data)
                {
                    temp = ptr->data ;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                }
                i=0 ;
            }
            ptr = ptr->next ;
        }
        return head ;
    }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.zigZag(head);
        print(ans);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends