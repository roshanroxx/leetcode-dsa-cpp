class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int cur=0;
        int count=0;
        for(int i =0;i<bank.size();i++){
            cur=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    cur++;
                }
            }
            if(cur>0){
                count += cur*prev;
                prev = cur;
            }
        }
        return count;
    }
};