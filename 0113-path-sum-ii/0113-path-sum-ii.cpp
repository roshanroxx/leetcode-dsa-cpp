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
    vector<vector<int>> v;
    void pp(TreeNode* root , int targetSum ,vector<int> &m)
    {
        if(root->right==NULL && root->left==NULL)
        {
            targetSum = targetSum - root->val;
            m.push_back(root->val);
            // cout<<targetSum<<" o ";
            if(targetSum==0)
            {
                // if(m==v.back())
                // {return;}
                v.push_back(m);
                // return;
            }
            m.pop_back();
            return;
        }
        // cout<<" k ";
        // if(root->val>targetSum)
        // {
        //     return;
        // }
        m.push_back(root->val);
        if(root->left!=NULL)
        {
            pp(root->left,targetSum - root->val,m);

        }
        if(root->right!=NULL)
        {
            pp(root->right,targetSum - root->val,m);

        }
        m.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return v;
        }
        vector<int> m;
        pp(root,targetSum,m);
        return v;
    }
};