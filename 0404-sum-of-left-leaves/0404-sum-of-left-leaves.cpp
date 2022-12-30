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
    int sum=0;
    void sumleft(TreeNode* root,bool a)
    {
        if(root==NULL){return;}
        if(root->left==NULL && root->right==NULL)
        {
            if(a==true)
            {
                sum = sum +root->val;
                return;
            }
            return;
        }
        sumleft(root->left , true);
        sumleft(root->right , false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right== NULL)
        {
            return 0;
        }
        sumleft(root,true);
        return sum;
    }
};