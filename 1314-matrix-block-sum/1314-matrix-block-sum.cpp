class Solution {
public:

    int pp(vector<vector<int>>& mat,int i,int j,int k){
        int p=0;
        for(int l=i-k;l<=i+k;l++){
            for(int m=j-k;m<=j+k;m++){
                if(l>=0 && l<mat.size() && m>=0 && m<mat[0].size()){
                    p+=mat[l][m];
                }
            }
        }
        return p;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> v(mat.size(),vector<int>(mat[0].size()));

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v[i][j] = pp(mat,i,j,k);
            }
        }
        return v;
    }
};