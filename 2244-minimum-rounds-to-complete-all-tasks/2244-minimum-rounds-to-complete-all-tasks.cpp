class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int res=0;
        for(auto i:tasks){
            mp[i]++;
        }
        for(auto& it:mp){
            if(it.second == 1){return -1;}
            else{
                res+=(it.second +2)/3;            }
        }
        return res;
        // unordered_map<int, int> count;
        // int res = 0, freq1;
        // for (int a: A)
        //     ++count[a];
        // for (auto& it: count) {
        //     if (it.second == 1) return -1;
        //     res += (it.second + 2) / 3;
        // }
        // return res;
    }
};