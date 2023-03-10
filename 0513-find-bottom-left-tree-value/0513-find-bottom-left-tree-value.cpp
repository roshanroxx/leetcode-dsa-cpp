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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> s;
        int ans;
        s.push(root);
        while(!s.empty()){
            int n = s.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = s.front();
                s.pop();
                if(i==0){
                    ans = curr->val;
                    // cout<<ans<<" ";
                }

                if(curr->left){
                    s.push(curr->left);
                }
                if(curr->right){
                    s.push(curr->right);
                }
            }
        }
        return ans;
    }
};