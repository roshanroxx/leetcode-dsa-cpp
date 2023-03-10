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
private:
    int pp(TreeNode* root, unordered_map<int,int>& mp,int& maxi){
        if(root==NULL){
            return 0;
        }
        int right = pp(root->right,mp,maxi)+ pp(root->left,mp,maxi) +root->val;
        mp[right]++;
        maxi = max(maxi,mp[right]);
        return right;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxi=0;
        int sum = pp(root,mp,maxi);
        // pair<int,int> p = {0,0};
        cout<<maxi;
        vector<int> sums;
        for(auto i:mp){
            if(i.second == maxi ){
                sums.push_back(i.first);
            }
        }
        return sums;
    }
};