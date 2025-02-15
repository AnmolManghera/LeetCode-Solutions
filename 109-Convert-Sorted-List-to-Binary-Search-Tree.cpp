/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode*prev = new ListNode();
        prev->next = head;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL && fast ->next !=NULL){
            prev = prev->next;
            slow=slow->next;
            fast =fast->next->next;
        }
        prev->next = NULL;
        TreeNode*curr = new TreeNode(slow->val);
        curr->left = sortedListToBST(head);
        curr->right = sortedListToBST(slow->next);
        return curr;
    }
};