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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp= p.first;
            int vertical=p.second.first;
            int horizontal=p.second.second;
            mpp[vertical][horizontal].insert(temp->val);
            if(temp->left){
                q.push({
                    temp->left,{
                        vertical-1,
                        horizontal+1
                    }
                });
            }
            if(temp->right){
                q.push({
                    temp->right,{
                        vertical+1,
                        horizontal+1
                    }
                });
            }

        }

      for(auto p:mpp){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
      } 
        return ans;
    }
};