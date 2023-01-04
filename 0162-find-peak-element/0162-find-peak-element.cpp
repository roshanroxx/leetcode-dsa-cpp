class Solution {
public:

    int kkk(vector<int>& nums,int slow,int fast)
    {
        if(fast<slow){return -1;}
        if(nums[slow]>nums[slow-1] && nums[slow]>nums[slow+1])
        {
            return slow;
        }
        if(nums[fast]>nums[fast-1] && nums[fast]>nums[fast+1])
        {
            return fast;
        }
        int mid = (slow+fast)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            return mid;
        }

        return max(kkk(nums,slow+1,mid-1),kkk(nums,mid+1,fast-1));
        


    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return 0;}
        if(nums[0]>nums[1]){return 0;}
        if(nums[n-1]>nums[n-2]){return n-1;}
        return kkk(nums,1,n-2);
        

    }
};