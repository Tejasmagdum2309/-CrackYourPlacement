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

    TreeNode* build(TreeNode* l1, TreeNode* l2){
          if(l1 == NULL && l2 == NULL) return NULL;

          if(l1 == NULL || l2 == NULL){
            if(l1 == NULL){
                return l2;
            }
            else{
                return l1;
            }
          }

          l1->val = (l1->val+l2->val);

          l1->left = build(l1->left,l2->left);
          l1->right = build(l1->right,l2->right);

          return l1;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return build(root1,root2);
    }
};