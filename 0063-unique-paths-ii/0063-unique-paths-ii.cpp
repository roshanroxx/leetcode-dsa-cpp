class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return 0;
        }
        int m = grid.size();
        int n =grid[0].size();
        bool one = false;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                one = true;
                grid[i][0]=0;
            }
            if(one==false){
                grid[i][0]=1;
            }
            // cout<<grid[i][0]<<" p ";
        }
        one = false;
        for(int i=1;i<n;i++){
            if(grid[0][i]==1){
                one = true;
                grid[0][i]=0;
            }
            if(one==false){
                grid[0][i]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                }
                else {
                    grid[i][j]= grid[i-1][j]+grid[i][j-1];
                }
            }
        }
        // for(auto x:grid){
        //     for(auto p :x){
        //         cout<<p<<" ";
        //     }
        //     cout<<endl;
        // }
        // return  grid[m-1][n-1];
        return grid[m-1][n-1];
    }
};