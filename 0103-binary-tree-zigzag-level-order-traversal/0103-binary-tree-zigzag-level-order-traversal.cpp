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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
        {
            return v; 
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(s1.empty()==false || s2.empty()==false)
        {
            vector<int> v1;
            vector<int> v2;
        
            while(s1.empty()==false)            
            {
                TreeNode* curr = s1.top();
                s1.pop();
                v1.push_back(curr->val);
                if(curr->left!=NULL){
                    s2.push(curr->left);
                }
                if(curr->right!=NULL){
                    s2.push(curr->right);
                }
            }
            v.push_back(v1);
        
            
            while(s2.empty()==false)
            {
                TreeNode* curr = s2.top();
                s2.pop();
                v2.push_back(curr->val);
                if(curr->right!=NULL){
                    s1.push(curr->right);
                }
                if(curr->left!=NULL){
                    s1.push(curr->left);
                }
            }
            if(v2.size()>0)
            {
                v.push_back(v2);  

            }
            

        }
        return v;
    }
};