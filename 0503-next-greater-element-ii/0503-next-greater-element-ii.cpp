class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
                // cout<<"bvikaenv";
                continue;
            }
            else if(nums[i]>nums[s.top()]){
                while(!s.empty() && nums[i]>nums[s.top()]){
                    v[s.top()] = nums[i];
                    s.pop();
                }
                s.push(i);
            }
            else if(nums[i]<=nums[s.top()]){
                s.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>nums[s.top()]){
                while(!s.empty() && nums[i]>nums[s.top()]){
                    v[s.top()] = nums[i];
                    s.pop();
                }
            }
        }
        // for(auto x:v){
        //     cout<<x<<" ";
        // }
        return v;
    }
};