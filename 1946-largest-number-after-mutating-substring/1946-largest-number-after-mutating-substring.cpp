class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int i=0;
        while(i<num.size() && (num[i]-'0'>=change[num[i]-'0'])){
            i++;
        }
        for(;i<num.size();i++){
            if(num[i]-'0'<=change[num[i]-'0']){
                num[i] = change[num[i]-'0'] +'0';
            }
            else{
                break;
            }
        }
        return num;
    }
};