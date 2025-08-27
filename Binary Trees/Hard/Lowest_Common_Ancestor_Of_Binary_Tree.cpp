/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* leftsubtree=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightsubtree=lowestCommonAncestor(root->right,p,q);
        if(leftsubtree==nullptr){
            return rightsubtree;
        } else if(rightsubtree==nullptr){
            return leftsubtree;
        }
        else{
            return root;
        }
        return root;
    }
};