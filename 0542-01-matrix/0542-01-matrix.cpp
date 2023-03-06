class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n =mat.size();
        int m =mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    v[i][j] = 0;

                }
            }
        } 
        vector<int> r= {1,-1,0,0};
        vector<int> cr= {0,0,1,-1};
        int count =1;
        while(!q.empty()){
            int p =q.size();
            for(int c=0;c<p;c++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    int row = i+r[l];
                    int clm = j+cr[l];
                    if(row>=0 && clm>=0 && row<n && clm<m && v[row][clm]==INT_MAX){
                        v[row][clm] = min(count,v[row][clm]);
                        q.push({row,clm});
                    }
                }

            }
            count++;
        }
        return v;
    }
};