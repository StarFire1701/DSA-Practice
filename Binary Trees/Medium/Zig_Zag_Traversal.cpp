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
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=1;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* var = q.front();
                q.pop();
                temp.push_back(var->val);
                if(var->left!=nullptr) q.push(var->left);
                if(var->right!=nullptr) q.push(var->right);
            }
            if(flag==-1){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            flag=flag==1?-1:1;
        }
        return ans;
    }
};