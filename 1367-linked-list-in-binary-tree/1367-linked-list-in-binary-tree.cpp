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
    bool same(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
        {
            return true;
        }

        if(head!=NULL && root!=NULL && head->val == root->val)
        {
            return (same(head->next,root->left) || same(head->next,root->right));
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool a=false,b=false;
        if(head->val==root->val)
        {
            a = same(head,root);
            if(a==true)
            {
                return true;
            }
        }
        if(root->left!=NULL){
            a = isSubPath(head , root->left);
        }
        if(root->right!=NULL)
        {
            b = isSubPath(head,root->right);
        }
        return (a || b);




    }
};
