class Solution {
public:
    #define pi pair<int,int> 
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pi> v;
        int n = reward1.size();
        for(int i=0;i<reward1.size();i++){
            v.push_back({reward1[i]-reward2[i],i});
        }
        sort(v.begin(),v.end());
        int point=0;
        for(int i=n-1;i>=0;i--){
            if(k){
                point+=reward1[v[i].second];
                k--;
            }
            else{
                point+=reward2[v[i].second];
            }
        }
        return point;
    }
};