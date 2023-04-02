class Solution {
public:
    int bs(vector<int>& po,int s,long long success){
        int n = po.size()-1;
        int l=0;
        int ans=INT_MAX;
        while(l<n){
            int mid = l +(n-l)/2;
            if(mid!=0 && (long long)s*po[mid] >=success && (long long)s*po[mid-1] <success){
                ans = mid;
            }
            if(mid!=po.size()-1 && (long long)s*po[mid+1] >=success && (long long)s*po[mid] <success){
                ans = mid+1;
            }
            if((long long)s*po[mid] >=success){
                n = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(ans==INT_MAX){
            if((long long)s*po[0]>=success){
                return po.size();
            }
            else{
                return 0;
            }
        }
        return po.size()-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& po, long long success) {
        sort(po.begin(),po.end());
        vector<int> v;
        for(int i=0;i<spells.size();i++){
            v.push_back(bs(po,spells[i],success));
        }
        return v;

    }
};