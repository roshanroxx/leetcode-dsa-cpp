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
    int prei=0;
    TreeNode* pp(vector<int> &pre,vector<int> &in,int ins,int ine)
    {
        if(ine<ins){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[prei++]);
        int index;
        for(int i=ins;i<=ine;i++)
        {
            if(root->val==in[i])
            {
                index = i;
                break;
            }
        }
        root->left = pp(pre,in,ins,index-1);
        root->right = pp(pre,in,index+1,ine);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ins = 0;
        int ine = preorder.size()-1;
        return pp(preorder,inorder,ins,ine);
    }
};