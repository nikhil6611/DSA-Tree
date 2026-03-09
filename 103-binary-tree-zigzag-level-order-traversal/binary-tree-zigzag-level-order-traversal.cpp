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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        stack<TreeNode*>s;
        bool flag=true;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            while(!s.empty()){
                temp.push_back(s.top()->val);
                s.pop();
            }
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(flag)temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                    if(flag)s.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                    if(flag)s.push(curr->right);
                }
            }
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};