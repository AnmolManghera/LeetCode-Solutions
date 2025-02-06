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
    vector<int>func(TreeNode* root,int &ans){
        if(!root) return {0,0};
        vector<int>l = func(root->left,ans);
        vector<int>r = func(root->right,ans);
        int val1 = root->val + l[1] + r[1];
        int val2 = max(l[0] + r[0] , l[1] + r[1]);
        ans = max(ans, max(val1,val2));
        return {max(root->val + l[1] + r[1], l[0] + r[0]), l[0] + r[0]};
    }
    int rob(TreeNode* root) {
        int ans = 0;
        func(root,ans);
        return ans;
    }   
};