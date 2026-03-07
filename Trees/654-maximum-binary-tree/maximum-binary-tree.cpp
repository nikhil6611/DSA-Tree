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
    TreeNode* buildtree(vector<int>&nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int max=INT_MIN;
        int idx;
        for(int i=left;i<=right;i++){
           if(nums[i]>max){
            idx= i;
            max=nums[i];
           }
        }
        TreeNode* root = new TreeNode(max);
        root->left = buildtree(nums,left,idx-1);
        root->right = buildtree(nums,idx+1,right);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildtree(nums,0,nums.size()-1);
    }
};