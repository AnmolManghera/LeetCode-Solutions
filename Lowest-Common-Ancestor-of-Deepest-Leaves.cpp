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
    TreeNode*lca (TreeNode*curr, TreeNode*a, TreeNode* b) {
        if(!curr) return NULL;
        if(curr == a || curr == b) {
            return curr;
        }
        TreeNode*left = lca(curr->left, a, b);
        TreeNode*right = lca(curr->right, a, b);
        if(right && left) return curr;
        return right ? right : left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        vector<TreeNode*>deepestNodes;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*>temp;
            while(sz--) {
                TreeNode*curr = q.front();
                q.pop();
                temp.push_back(curr);
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            deepestNodes = temp;
        }
        return lca(root, deepestNodes.front(),deepestNodes.back());
    }
};