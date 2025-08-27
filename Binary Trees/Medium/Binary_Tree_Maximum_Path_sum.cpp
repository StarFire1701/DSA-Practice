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
    int maxi=INT_MIN;
    int calculate_maxsum(TreeNode* root){
        if(root==nullptr)return 0;
        int sum=root->val;
        int left_sum=max(0,calculate_maxsum(root->left));
        int right_sum=max(0,calculate_maxsum(root->right));
        sum+=left_sum+right_sum;
        maxi=max(maxi,sum);
        return max(left_sum,right_sum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=calculate_maxsum(root);
        return maxi;
    }
};