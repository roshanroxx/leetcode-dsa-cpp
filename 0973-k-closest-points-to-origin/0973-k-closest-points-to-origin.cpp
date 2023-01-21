class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,int>> pq;
        for(int i=0;i<k;i++)
        {
            long long p = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({p,i});
            // cout<<pq.top().second<<"o ";
        }
        for(int i=k;i<points.size();i++)
        {
            long long p = pow(points[i][0],2)+pow(points[i][1],2);
            // cout<<"t ";
            if(p<pq.top().first)
            {
                // cout<<pq.top().second<<"p ";
                pq.pop();
                pq.push({p,i});
            }
        }
        vector<vector<int>> v;
        for(int i=0;i<k;i++)
        {
            v.push_back(points[pq.top().second]);
            
            pq.pop();
        }
        return v;


    }
};