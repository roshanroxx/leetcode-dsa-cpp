class Solution {
public:
    int count(vector<int>& v)
    {
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
            {
                count++;
            }
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({count(mat[i]),i});
            // cout<<pq.top().first<<" "<<pq.top().second<<" o ";
        }

        

        for(int i=k;i<mat.size();i++)
        {
            int l = count(mat[i]);
            if(l<pq.top().first)
            {
                pq.pop();
                pq.push({l,i});
                // cout<<pq.top().second<<"  oo ";
            }
        }
        vector<int> v;
        while(pq.empty()==false)
        {
            // cout<<pq.top().first<<" "<<pq.top().second<<" o ";
            v.push_back(pq.top().second);
            // cout<<
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};