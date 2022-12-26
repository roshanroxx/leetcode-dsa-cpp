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
    int k=0;

    int lengthh(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l = lengthh(root->left);
        int r = lengthh(root->right);
        k = max(k,1+l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int m =lengthh(root);
        return max(k,m)-1;
    }
};