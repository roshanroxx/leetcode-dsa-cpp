class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int k =pq.size();
        if(k>2)
        {
            int m=0;
            int p = pq.top();
            while(pq.size()!=0)
            {
            if(m==2)
            {
                break;
            }
            int t = pq.top();
            pq.pop();
            k--;
            if(t!=pq.top())
            {
                m++;
            }

            }
            if(pq.size()==0 && m<2)
            {
                return p;
            }

            return pq.top();
        }
        else{
            return pq.top();
        }
    }
};