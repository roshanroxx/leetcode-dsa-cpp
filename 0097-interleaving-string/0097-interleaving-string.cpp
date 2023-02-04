class Solution {
public:

    bool isans(string a,string b,string c){
        if(c.length()==0 && a.length()==0 && b.length()==0){
            return true;
        }
        bool k=false,l=false;
        if(a.length()>0 && c[0]==a[0]){
            k = isans(a.substr(1),b,c.substr(1));
        }
        if(b.length()>0 && c[0]==b[0]){
            l = isans(a,b.substr(1),c.substr(1));
        }
        return k || l;

    }
    bool isInterleave(string a, string b, string c) {
        if(c.length()!=a.length()+b.length()){
            return false;
        }
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
        dp[0][0]=1;
        bool m=true;
        int j=0;
        for(int i=1;i<=a.length();i++){
            if(m==true && a[i-1]==c[j]){
                dp[i][0] = 1;
                j++;
            }
            else{
                m=false;
            }
        }
        m=true;
        j=0;
        for(int i=1;i<=b.length();i++){
            if(m==true && b[i-1]==c[j]){
                dp[0][i] = 1;
                j++;
            }
            else{
                m=false;
            }
        }
        for(int i=1;i<=a.size();i++){
            for(j=1;j<=b.size();j++){
                if(dp[i-1][j]==1 && a[i-1]==c[i+j-1]){
                    dp[i][j]=1;
                }
                else if(dp[i][j-1]==1 && b[j-1]==c[i+j-1]){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[a.size()][b.size()];
    }
};