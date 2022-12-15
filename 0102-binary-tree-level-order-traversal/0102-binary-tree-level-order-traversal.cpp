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
    void leveltraverse(TreeNode* root ,vector<vector<int>> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int count = q.size();
            vector<int> v2;
            for(int i =0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr==NULL)
                {
                    continue;
                }
                v2.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if(v2.size()>0)
            {
                v1.push_back(v2);

            }
            v2.clear();
        }
        return;

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        leveltraverse(root , v);
        return v;
    }
};