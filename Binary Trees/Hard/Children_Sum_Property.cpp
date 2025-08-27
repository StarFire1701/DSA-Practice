/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool ischildrensum(TreeNode* root){
        if(root==nullptr) return true;
        if(root->left==nullptr && root->right==nullptr) return true;
        int sum=0;
        if(root->left){
            sum+=root->left->val;
        }
        if(root->right){
            sum+=root->right->val;
        }
        if(sum!=root->val) return false;
        return (ischildrensum(root->left)&&ischildrensum(root->right));

    }
    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
     return ischildrensum(root);
    }
};
