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
    TreeNode* build_tree(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int posstart,int posend,map<int,int>&mpp){
        if(instart>inend || posstart>posend) return nullptr;
        TreeNode* root = new TreeNode(postorder[posend]);
        int inroot=mpp[postorder[posend]];
        int numsleft=inroot-instart;
        root->left=build_tree(inorder,instart,inroot-1,postorder,posstart,posstart+numsleft-1,mpp);
        root->right=build_tree(inorder,inroot+1,inend,postorder,posstart+numsleft,posend-1,mpp);
        return root;
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())return nullptr;
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=build_tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};