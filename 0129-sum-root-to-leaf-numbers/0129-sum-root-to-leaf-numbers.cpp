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
    // int sum=0;
private:
    void pp(TreeNode* root,int n,int &sum){
        if(root==NULL){
            // sum+=n;
            return;
        }
        n = 10*n+root->val;
        if(!root->left && !root->right){
            sum+=n;
            return;
        }
        // cout<<n<<endl;
        pp(root->right,n,sum);
        pp(root->left,n,sum);
        // n=n/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int n=0;
        int sum=0;
        pp(root,n,sum);
        return sum;
    }
};