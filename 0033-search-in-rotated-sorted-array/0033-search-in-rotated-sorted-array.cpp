class Solution {
public:
    int search(vector<int>& nums, int t) {
        int st=0,en = nums.size()-1;
        while(st<=en){
            int mid = (st+en)/2;
            if(nums[mid] == t){return mid;}
            // cout<<mid<<" ";
            if(nums[st]<=nums[mid]){
                if(t>=nums[st] && t<nums[mid]){
                    en = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            else{
                if(t>nums[mid] && t<=nums[en]){
                    st = mid+1;
                }
                else{
                    en = mid-1;
                }
            }
        }
        return -1;
    }
};