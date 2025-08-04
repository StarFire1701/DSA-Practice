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
    vector<int>calculate_preorder(TreeNode* root){
        vector<int>ans;
        if(root==nullptr)return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            if(temp==nullptr){
                ans.push_back(INT_MIN);
                continue;
            }else{ ans.push_back(temp->val);}
                st.push(temp->right);
                st.push(temp->left);
        }
        return ans;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>preorder_of_p=calculate_preorder(p);
        vector<int>preorder_of_q=calculate_preorder(q);
        int n=preorder_of_p.size();
        int m=preorder_of_q.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(preorder_of_p[i]!=preorder_of_q[i]) return false;
        }
        return true;
    }
};