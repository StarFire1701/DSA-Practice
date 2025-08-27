/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string s="";
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        TreeNode*temp=q.front();
        q.pop();
        if(temp==nullptr){
            s+="#,";
        } else{
            s+=to_string(temp->val)+",";
            q.push(temp->left);
            q.push(temp->right);
        }
      }
      return s;  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        if (str == "#" || str.empty()) return nullptr;  // extra safet
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
             TreeNode* temp = q.front();
        q.pop();

        if (!getline(s, str, ',')) break;
        if (str != "#" && !str.empty()) {
            TreeNode* leftnode = new TreeNode(stoi(str));
            temp->left = leftnode;
            q.push(leftnode);
        }

        if (!getline(s, str, ',')) break;
        if (str != "#" && !str.empty()) {
            TreeNode* rightnode = new TreeNode(stoi(str));
            temp->right = rightnode;
            q.push(rightnode);
        }
    }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));