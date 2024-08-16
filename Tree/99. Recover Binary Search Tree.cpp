/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* A) {
    vector<TreeNode*> v;
    TreeNode* curr = A;TreeNode* pre = new TreeNode(INT_MIN);
    
    while(curr != NULL){
        if(curr->left == NULL){
            if(pre->val > curr->val){
                v.push_back(pre);v.push_back(curr);
            }
            pre = curr;
            curr = curr->right;
        }
        else{
            TreeNode* p = curr->left;
            while(p->right != NULL && p->right != curr){
                p = p -> right;
            }
            
            if(p->right == NULL){
                p->right = curr;
                curr = curr->left;
            }
            else{
                if(  pre->val > curr->val){
                v.push_back(pre);v.push_back(curr);
                }
                pre = curr;   
                p->right = NULL;
                curr = curr->right;
            }
        }
    }
    // cout<<v.size()<<" ";
    for(TreeNode* t : v){
        cout<<t->val<<" ";
    }
    if(v.size() == 4){
        int l = v[0]->val;
        int r = v[3]->val;

        v[0]->val = r;
        v[3]->val = l;
    }
    else{
        int l = v[0]->val;
        int r = v[1]->val;

        v[0]->val = r;
        v[1]->val = l;
    }
        
    }
};