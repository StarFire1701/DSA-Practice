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
        
        TreeNode* markparents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_map,int start){
            TreeNode*begin=nullptr;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode*current=q.front();
                if(current->data==start) begin=current;
                q.pop();
                if(current->left){
                    q.push(current->left);
                    parent_map[current->left]=current;
                }
                if(current->right){
                    q.push(current->right);
                    parent_map[current->right]=current;
                }
            }
            return begin;
        }
		int timeToBurnTree(TreeNode* root, int start){
            //your code goes here
            if(root==nullptr)return 0;
            unordered_map<TreeNode*,TreeNode*>parent_map;
            TreeNode*begin=markparents(root,parent_map,start);
            int time=0;
            unordered_map<TreeNode*,bool>visited;
            queue<TreeNode*>q;
            q.push(begin);
            visited[begin]=true;
            while(!q.empty()){
                int n=q.size();
                bool b=false;
                for(int i=0;i<n;i++){
                 TreeNode*temp=q.front();
                 q.pop();
                 if(temp->left && !visited[temp->left]){
                    b=true;
                    q.push(temp->left);
                    visited[temp->left]=true;
                 }
                 if(temp->right && !visited[temp->right]){
                    b=true;
                    q.push(temp->right);
                    visited[temp->right]=true;
                 }
                 if(parent_map[temp] && !visited[parent_map[temp]]){
                    b=true;
                    q.push(parent_map[temp]);
                    visited[parent_map[temp]]=true;
                 }
            }

            if(b)time+=1;
            }
            return time;
		}	
};