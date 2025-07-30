//Brute Force
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
    int maxi=0;
    int calc_height(TreeNode* root){
        if(root==nullptr) return 0;
        int left_height=calc_height(root->left);
        int right_height=calc_height(root->right);
        return 1+max(left_height,right_height);
    }
    void longest_diameter(TreeNode* root){
        if(root==nullptr)return;
        int left_height=calc_height(root->left);
        int right_height=calc_height(root->right);
        maxi=max(maxi,left_height+right_height);
        longest_diameter(root->left);
        longest_diameter(root->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        longest_diameter(root);
        return maxi;
    }
};

//Optimal Solution

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
    int maxi=0;
    int calc_diameter(TreeNode* root){
        if(root==nullptr)return 0;
        int left_height=calc_diameter(root->left);
        int right_height=calc_diameter(root->right);
        maxi=max(maxi,left_height+right_height);
        return 1+max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=calc_diameter(root);
        return maxi;
    }
};