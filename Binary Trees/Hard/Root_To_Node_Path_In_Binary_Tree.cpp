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
        void find_path(TreeNode* root,vector<int>&temp_path,vector<vector<int>>&ans){
            if(root->left==nullptr && root->right==nullptr){
                temp_path.push_back(root->data);
                ans.push_back(temp_path);
                temp_path.pop_back();
                return;
            }
            temp_path.push_back(root->data);
            if(root->left){
                 find_path(root->left,temp_path,ans);
            } 
            if(root->right){
                 find_path(root->right,temp_path,ans);
            }
            temp_path.pop_back();
        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>>ans;
            if(root==nullptr)return ans;
            vector<int>temp_path;
            find_path(root,temp_path,ans);
            return ans;
		}
};