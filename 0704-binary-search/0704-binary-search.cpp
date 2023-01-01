class Solution {
public:

    int searchh(vector<int> &v,int s,int l , int t )
    {
        if(s>l)
        {
            return -1;
        }
        int mid = (s+l)/2;
        if(v[mid] == t)
        {
            return mid;
        }
        else if(v[s]==t)
        {
            return s;
        }
        else if(v[l]==t)
        {
            return l;
        }
        else{
            return max(searchh(v,s+1,mid-1,t),searchh(v,mid+1,l-1,t));
        }
    }
    int search(vector<int>& nums, int target) {
        int s=0;
        int l = nums.size()-1;
        return searchh(nums,s,l,target);
    }
};