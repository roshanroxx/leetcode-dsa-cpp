class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum= 0;
        sort(beans.begin(),beans.end());
        for(int i=0;i<beans.size();i++)
        {
            sum+=beans[i];
        }
        long long mini=LONG_MAX;
        int n=beans.size();
        cout<<sum<<endl;
        for(int i=0;i<n;i++)
        {
            // sum = sum -beans[i];
            // int k =sum - 
            // if()
            long long k = beans[i];
            k = k*(n-i);
            mini = min(mini,sum-k);
            // cout<<k<<" o ";
            // if(mini>=sum-k)
            // {
            //     mini = sum-k;
            // }
        }
        // cout<<sum;
        return mini;
    }
};