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
    void compute_inorder(TreeNode* root,vector<int>&temp){
        if(root==nullptr){
            return ;
        }
        compute_inorder(root->left,temp);
        temp.push_back(root->val);
        compute_inorder(root->right,temp);
        return ;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>temp;
        compute_inorder(root,temp);
        return temp;
    }
};