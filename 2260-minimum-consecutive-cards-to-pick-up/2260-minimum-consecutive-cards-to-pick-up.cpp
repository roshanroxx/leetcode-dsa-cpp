class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int k = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(mp.find(cards[i])==mp.end()){
                mp[cards[i]] = i;
            }
            else{
                k = min(k,-mp[cards[i]] + i+1);
                mp[cards[i]] = i;
            }
        }
        if(k==INT_MAX){
            return -1;
        }
        return k;
    }
};
