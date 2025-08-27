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
    int find_left_height(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int find_right_height(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int left_height=find_left_height(root);
        int right_height=find_right_height(root);
        if(left_height==right_height){
            return (1<<left_height)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};