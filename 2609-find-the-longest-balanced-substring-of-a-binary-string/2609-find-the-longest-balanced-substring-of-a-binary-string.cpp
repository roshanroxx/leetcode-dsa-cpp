class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int sum=0;
        int cnt=0;
        int k=0;
        int ans=0;
        for(int i=0;i<s.size();){
            while(s[i]=='0'){
                sum-=1;
                i++;
            }
            k = abs(sum);
            while(s[i]=='1'){
                sum+=1;
                i++;
            }
            if(sum>=0){
                cnt=k*2;
            }
            else{
                cnt = abs(sum+k)*2;
            }
            sum=0;
            ans = max(ans,abs(cnt));
        }
        return abs(ans);
    }
};