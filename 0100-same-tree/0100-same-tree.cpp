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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL)
        {
            if(q==NULL)
            {
                return true;
            }
            else{return false;}
        }
        if(p!=NULL && q==NULL)
        {
            return false;
        }
        
        if(p->val==q->val)
        {
            
            if(isSameTree(p->left,q->left)==true && isSameTree(p->right,q->right)==true)
            {
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};