class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1,0);
        for(auto p:trust){
            count[p[0]]--;
            count[p[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};