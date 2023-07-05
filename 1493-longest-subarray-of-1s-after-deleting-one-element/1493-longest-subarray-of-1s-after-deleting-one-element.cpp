class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int j1=-1,j2=-1,cnt=0,cnt2=0,cnt3=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                cnt++;
            }
            if(arr[i]==0){
                if(cnt3==1){
                    j1=j2;
                    j2=i;
                    cnt2=cnt;
                    cnt=0;
                }
                else{
                    cnt3++;
                    j2=i;
                    cnt2 = cnt;
                    cnt=0;
                }
            }
            // cout<<i<<" "<<j1<<" "<<j2<<" "<<cnt<<" "<<cnt2<<" "<<cnt3<<" "<<endl;
            ans = max(ans,cnt2+cnt);
        }
        if(cnt3==0){
            return ans-1;
        }
        return ans;
    }
};