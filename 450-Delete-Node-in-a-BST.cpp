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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if(key == root->val){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(root->left && root->right){
                TreeNode*temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
                return root;
            }
            TreeNode*temp = root->right ? root->right : root->left;
            delete root;
            return temp;
        }
        else{
            root->left = deleteNode(root->left, key);
            return root;   
        }
    }
};