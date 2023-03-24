class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int c=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                c++;
            }
            else{
                mp[secret[i]]++;

            }
            // mp[guess[i]]--;
        }
        int k=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]!=guess[i] && mp[guess[i]]>0){
                mp[guess[i]]--;
                k++;
            }
        }
        // for(auto p :mp){
        //     if(p.second==0){
        //         mp.erase(p.first);
        //     }
        //     else if(p.second<){
        //         k+=p.second;
        //     }
        // }
        string ans = to_string(c)+'A'+to_string(k)+'B';
        return ans;
    }
};