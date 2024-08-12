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
    
    void travel(TreeNode* root,int& k,int& n,int& ans){
        if(root == NULL) return;
        travel(root->left,k,n,ans);
        
        cout<<n<<"-"<<root->val<<" ";
        if(k == n++){
            ans = root->val;
        }
        travel(root->right,k,n,ans);

    }

    int kthSmallest(TreeNode* root, int k) {
        int n = 1;
        int ans = -1;
        travel(root,k,n,ans);

        return ans; 
    }
};