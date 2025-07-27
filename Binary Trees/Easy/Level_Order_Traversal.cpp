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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            if(size==0) {
                return ans;
            }
            for(int i=0;i<size;i++){
                TreeNode*t1=q.front();
                q.pop();
                temp.push_back(t1->val);
                if(t1->left!=nullptr){
                    q.push(t1->left);
                }
                if(t1->right!=nullptr){
                    q.push(t1->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};