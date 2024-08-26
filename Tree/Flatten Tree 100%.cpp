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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;

        if(root == NULL) return;
        
        TreeNode* ans = root;
        TreeNode* pre;
        
        while(root != NULL || !st.empty()){
             if(root != NULL){
                if(root->right != NULL) st.push(root->right);
                 TreeNode* l = root->left;
                root->left = NULL; 
                root->right = l;
                pre = root;
                root = root->right;
                
             }
             else{
                 TreeNode* tp = st.top();
                st.pop();
                root = pre;
                root->right = tp;
                root = root->right;
             }
        }
        
        root = ans;
        
    }
};