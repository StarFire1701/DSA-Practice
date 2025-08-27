/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int>ans;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int val=p.second;
            if(mpp.find(val)==mpp.end()){
                mpp[val]=temp->data;
            }
            if(temp->left){
                q.push({temp->left,val-1});
            }
            if(temp->right){
                q.push({temp->right,val+1});
            }
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};