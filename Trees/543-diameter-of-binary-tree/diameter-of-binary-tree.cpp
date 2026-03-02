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
    int ht(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = ht( root->left);
        int right = ht( root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int rootht = ht(root->left)+ht(root->right);
       int left= diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
    return max({rootht,left,right});
    }
};