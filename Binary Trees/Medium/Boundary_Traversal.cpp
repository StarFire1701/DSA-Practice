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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    void addLeftboundary(TreeNode* root,vector<int>&ans){
        TreeNode*curr=root->left;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr=curr->left;
            } else curr=curr->right;
        }
    }
    void addLeaves(TreeNode* root,vector<int>&ans){
        TreeNode*curr=root;
        if(isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) addLeaves(curr->left,ans);
        if(curr->right) addLeaves(curr->right,ans);
    }
    void addRightboundary(TreeNode* root,vector<int>&ans){
        TreeNode*curr=root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
               curr=curr->right;
            } else curr= curr->left;
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }

    }
    vector <int> boundary(TreeNode* root){
    	//your code goes here
        vector<int>ans;
        if(root==nullptr) return ans;
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        addLeftboundary(root,ans);
        addLeaves(root,ans);
        addRightboundary(root,ans);
        return ans;
    }
};