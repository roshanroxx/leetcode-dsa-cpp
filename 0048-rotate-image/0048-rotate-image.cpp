class Solution {
public:

    void transpose(vector<vector<int>>& m)
    {
        for(int i= m.size()-1;i>=0;i--)
        {
            for(int j=0;j<=m.size()-i-1;j++)
            {
                swap(m[i][j],m[m.size()-j-1][m.size()-i-1]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
       transpose(matrix);

        for(int i=0;i<matrix.size()/2;i++)
        {
            for(int j=0 ; j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[matrix.size()-i-1][j]);
            }
        }
       return;
    }
};