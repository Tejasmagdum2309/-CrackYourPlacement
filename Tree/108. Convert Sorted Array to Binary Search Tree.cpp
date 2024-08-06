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
    
    TreeNode* create(vector<int>& nums,int i,int j){
        if(i > j || i > nums.size() || j < 0) return NULL;

        int mid = (i+j)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = create(nums,i,mid-1);
        root->right = create(nums,mid+1,j);

        return root;
    }
  
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums,0,nums.size()-1);
    }
};