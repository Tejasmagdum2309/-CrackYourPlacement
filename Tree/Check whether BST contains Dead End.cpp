//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
   
    
    
    
    bool isDeadEnd(Node *root)
    { vector<int> sa;
    vector<int> leaf;
        //Your code here
        stack<Node*> st;
        while(!st.empty() || root != NULL){
             if(root != NULL){
                 st.push(root);
                 root = root->left;
             }
             else{
                 root = st.top();
                 st.pop();
                 
                 sa.push_back(root->data);
                 if(root->right == NULL && root->left == NULL){
                     leaf.push_back(root->data);
                 }
                 root = root->right;
             }
        }
        
        
        int j = 0;
        for(int i = 0;i<sa.size();i++){
            if(leaf[j] == sa[i]){
                if(sa[i-1] == leaf[j] -1 && sa[i+1] == leaf[j] + 1){
                    return true;
                }
                j++;
                
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends