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
    TreeNode* func(int &idx, string &t, int expLevel){
        int i = idx - 1;
        int cntDashes = 0;
        while(i >= 0 && t[i] == '-'){
            cntDashes++;
            i--;
        }
        if(cntDashes != expLevel){
            // means this call is incorrect
            return NULL;
        }
        //get the value
        string temp = "";
        while(idx < t.length() && t[idx] != '-'){
            temp += t[idx];
            idx++;
        }
        TreeNode* root = new TreeNode(stoi(temp));
        // take the idx to the next place
        while(idx < t.length() && t[idx] == '-'){
            idx++;
        }
        root->left = func(idx,t,expLevel+1);
        root->right = func(idx,t,expLevel+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return func(idx,traversal,0);
    }
};