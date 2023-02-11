class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> v(nums.size()+1,vector<int>(3,0));
        for(int i=0;i<3;i++){
            v[0][i]=0;
        }
        for(int i=0;i<nums.size();i++){
            for(int m=0;m<3;m++){
                v[i+1][m] = v[i][m];
            }
            for(int j=0;j<3;j++){
                // if(v[i+1][j]==0){
                    
                // }
                int k = nums[i] + v[i][j];
                int l =k%3;
                if(v[i+1][l]<k){
                    v[i+1][l] = k;
                }
            }
        }
        // for(auto p:v){
        //     for(auto q:p){
        //         cout<<q<<" ";
        //     }
        //     cout<<endl;
        // }
        return v[nums.size()][0];
    }
};