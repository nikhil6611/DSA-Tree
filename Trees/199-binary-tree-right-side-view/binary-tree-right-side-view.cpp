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
    void helper(TreeNode* root, int level, int&maxlevel,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(maxlevel<level){
            ans.push_back(root->val);
            maxlevel=level;
        }
        helper(root->right,level+1,maxlevel,ans);
        helper(root->left,level+1,maxlevel,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int maxlevel=0;
        vector<int>ans;
        helper(root,1,maxlevel,ans);
        return ans;
    }
};