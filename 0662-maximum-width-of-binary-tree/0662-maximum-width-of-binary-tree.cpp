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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long >> q;
        long long ans=1;
        q.push({root,1});
        long long cnt=-1;
        int prev=0,n;
        while(!q.empty()){
            n= q.size();
            cnt++;
            prev = q.front().second;
            for(int i=0;i<n;i++){
                pair<TreeNode*,long long> curr = q.front();
                cout<<curr.second<<" ";
                q.pop();
                if(i!=0){
                    ans = max(ans, curr.second - prev +1);
                }
                if(curr.first->left!=NULL){
                    q.push({curr.first->left,(curr.second - prev)*2 +1});
                }
                if(curr.first->right!=NULL){
                    q.push({curr.first->right,(curr.second - prev)*2 +2});
                }
            }
        }
        return ans;

    }
};