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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long offset = q.front().second;  

            int start = q.front().second - offset; 
            int end   = q.back().second - offset;  

            ans = max(ans, end-start+1);

            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                long long idx = curr.second - offset; // ⭐ added

                if(curr.first->left)
                    q.push({curr.first->left, 2*idx+1});
                if(curr.first->right)
                    q.push({curr.first->right, 2*idx+2});
            }
        }
        return ans;
    }
};