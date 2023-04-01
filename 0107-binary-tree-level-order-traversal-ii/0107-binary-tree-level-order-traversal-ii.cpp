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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){return {};}
        queue<TreeNode*> q;
        q.push(root);
        int n;
        TreeNode* curr;
        vector<vector<int>> v;
        vector<int> k;
        while(!q.empty()){
            n = q.size();
            for(int i=0;i<n;i++){
                curr = q.front();q.pop();
                k.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            v.push_back(k);
            k.clear();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};