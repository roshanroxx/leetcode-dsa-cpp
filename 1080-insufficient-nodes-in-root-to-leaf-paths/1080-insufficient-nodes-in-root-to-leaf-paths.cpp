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

    bool pp(TreeNode* root,int l,int sum)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val<l)
            {
                return false;
            }
            return true;
        }
        bool left = pp(root->left ,l,sum+root->val );
        bool right = pp(root->right ,l,sum+root->val );
        if(left==false)
        {
            root->left = NULL;
        }
        if(right==false)
        {
            root->right=NULL;
        }
        if(left==true || right==true)
        {
            return true;
        }
        return false;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* temp =root;
        bool k =pp(root,limit,0);
        if(k==false)
        {
            return NULL;
        }
        return temp;
    }
};