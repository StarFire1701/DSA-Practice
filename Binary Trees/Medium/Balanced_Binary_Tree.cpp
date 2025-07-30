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
    int maxdepth(TreeNode* root){
        if(root==nullptr)return 0;
        int left_side=maxdepth(root->left);
        if(left_side==-1) return -1;
        int right_side=maxdepth(root->right);
        if(right_side==-1) return -1;
        if(abs(left_side-right_side)>1) return -1;
        return 1+max(left_side,right_side);
    }
    bool isBalanced(TreeNode* root) {
        return (maxdepth(root)!=-1);
    }
};