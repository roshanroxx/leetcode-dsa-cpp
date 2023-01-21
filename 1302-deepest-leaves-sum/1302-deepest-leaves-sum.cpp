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

    pair<int,int> pp(TreeNode* root,int dep,int& sum)
    {
        if(root==NULL)
        {
            return{-1,-1};
        }
        if(root->left==NULL && root->right==NULL)
        {
            pair<int,int> p;
            p.first = root->val;
            p.second = dep;
            return p;
        }
        pair<int ,int> ple = pp(root->left,dep+1,sum);
        pair<int ,int> pre = pp(root->right,dep+1,sum);
        // if(root->left!=NULL)
        // {
        // }
        // if(root->right!=NULL)
        // {
        // }

        if(ple.second>pre.second)
        {
            return ple;
        }
        else if(ple.second<pre.second)
        {
            return pre;
        }
        else{
            ple.first +=pre.first;
            return ple;
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        pair<int,int> p = pp(root,1,sum);
        return p.first;
    }
};