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
    int posti=0;
    TreeNode* pp(vector<int>& in,vector<int>& post,int ins,int ine)
    {
        if(ine<ins)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(post[post.size()-1-posti++]);
        int index;
        for(int i=ins;i<=ine;i++)
        {
            if(root->val == in[i])
            {
                index=i;
                break;
            }
        }
        root->right = pp(in,post,index+1,ine);
        root->left = pp(in,post,ins,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return pp(inorder,postorder,0,inorder.size()-1);
    }
};