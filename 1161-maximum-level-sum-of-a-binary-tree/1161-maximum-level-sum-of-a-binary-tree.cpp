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

    pair<int,int> maxi;
    void pp(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        maxi.first = root->val;
        int level =1;
        maxi.second =level;
        while(q.empty()==false)
        {
            int count = q.size();
            int sum=0;
            cout<<" o ";
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum = sum+curr->val;
                cout<<sum<<" p ";
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            if(maxi.first<sum)
            {
                maxi.first = sum;
                maxi.second = level;
            }
            // maxi.first = max(maxi.first,sum);
            level++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        pp(root);
        return maxi.second;
    }
};
