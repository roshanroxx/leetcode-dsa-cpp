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
    int ans = 0;
    /*
        {distance , coins , bdistance,bcoin}
    */
    int pp(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = pp(root->left);
        int right = pp(root->right);
        // cout<<left<<"  "<<right<<endl;
        ans = ans + abs(left) +abs(right);
        return (left +right+root->val -1);
        
    }
    int distributeCoins(TreeNode* root) {
        // int ans =0;
        int temp = pp(root);
        return ans;
    }
};