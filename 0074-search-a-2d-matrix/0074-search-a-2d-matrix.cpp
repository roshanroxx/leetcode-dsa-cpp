class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();


        for(int i=0,j=n-1;i<m && j>=0;)
        {
            // cout<<i<<"  "<<j<<"  ";
            int k =matrix[i][j];
            if(k == target)
            {
                return true;
            }
            else if(k<target)
            {
                i++;
            }
            if(k == target)
            {
                return true;
            }
            else if(k>target)
            {
                j--;
            }
        }
        return false;
    }
};