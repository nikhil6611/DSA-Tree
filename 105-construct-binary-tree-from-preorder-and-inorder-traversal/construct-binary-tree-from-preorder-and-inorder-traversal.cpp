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
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder,int &preidx,int left,int right){
        if(left>right){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preidx]);
        preidx++;
        int inidx= search(inorder,root->val,left,right);
        root->left = bt(preorder,inorder,preidx,left,inidx-1);
        root->right = bt(preorder,inorder,preidx,inidx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx=0;
      return  bt(preorder,inorder,preidx,0,preorder.size()-1);
        
    }
};