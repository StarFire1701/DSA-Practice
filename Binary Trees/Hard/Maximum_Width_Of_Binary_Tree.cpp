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
        if(root==nullptr)return 0;
        long long ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long first_index,last_index;
            long long mini=q.front().second;
            for(int i=0;i<n;i++){
                long long curr_index=q.front().second;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first_index=curr_index;
                if(i==n-1) last_index=curr_index;
                if(node->left){
                    q.push({node->left,2*curr_index+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_index+2});
                }
            }
            ans=max(ans,last_index-first_index+1);
        }
        return (int)ans;
    }
};