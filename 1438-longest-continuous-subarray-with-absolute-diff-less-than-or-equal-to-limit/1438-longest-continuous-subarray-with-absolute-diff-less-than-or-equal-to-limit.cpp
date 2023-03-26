class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int cnt= 0;
        int dif =0;
        s.insert(nums[0]);
        cnt =1;
        int ans=1;
        for(int i=1,j=0;i<nums.size();i++){
            s.insert(nums[i]);
            cnt++;
            // dif = *s.rbegin() - *s.begin();
            cout<<*s.begin()<<"  "<<s.size()<<" p ";
            if(*s.rbegin() - *s.begin() > limit){
                while((*s.rbegin() - *s.begin()) > limit){
                    s.erase(s.find(nums[j++]));
                    cnt--;
                }
                // cnt--;
            }
            cout<<ans<<endl;
            ans =max(ans,cnt);
            // else{
            //     // cnt++;
            //     // s.insert(num[i]);
            // }
        }
        return ans;
    }
};