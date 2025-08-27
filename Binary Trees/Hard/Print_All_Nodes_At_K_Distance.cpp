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
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_map,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*current=q.front();
            q.pop();
            if(current->left){
                parent_map[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_map[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==nullptr)return ans;
        unordered_map<TreeNode*,TreeNode*>parent_map;
        markparents(root,parent_map,target);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            dist++;
            for(int i=0;i<n;i++){
                TreeNode*current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_map[current] && !visited[parent_map[current]]){
                    q.push(parent_map[current]);
                    visited[parent_map[current]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode*temp_node=q.front();
            q.pop();
            ans.push_back(temp_node->val);
        }

        return ans;
    }
};