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
    TreeNode* build_tree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mpp){
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* start=new TreeNode(preorder[prestart]);
        int inroot=mpp[start->val];
        int numsleft=inroot-instart;
        start->left=build_tree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
        start->right=build_tree(preorder,prestart+1+numsleft,preend,inorder,inroot+1,inend,mpp);
        return start;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())return nullptr;
        int n=inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=build_tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};