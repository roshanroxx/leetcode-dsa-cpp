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
    int mini =INT_MAX;
    void mind(TreeNode* root, int &pre){
        if(root!=NULL){
            mind(root->left,pre);
            if(pre!=-1){
                mini = min(mini , root->val - pre);
            }
            pre = root->val;
            mind(root->right,pre);
        }
    }
    int minDiffInBST(TreeNode* root) {
        int pre =-1;
        mind(root, pre);
        return mini;
    }
};