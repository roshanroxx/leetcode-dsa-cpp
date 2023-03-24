class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,pair<int,char>>> pq;
        if(a>0)pq.push({a,{0,'a'}});
        if(b>0)pq.push({b,{0,'b'}});
        if(c>0)pq.push({c,{0,'c'}});
        if(pq.empty()) return "";
        string ans="";
        while(pq.size()>1){
            auto p = pq.top();
            pq.pop();
            // cout<<ans<<endl;
            if(p.second.first ==2){
                auto l = pq.top();
                pq.pop();
                ans.push_back(l.second.second);
                l.first-=1;
                p.second.first =0;
                if(l.first>0){
                    pq.push(l);
                }
            }
            else{
                ans.push_back(p.second.second);
                p.second.first++;
                p.first--;

            }
            if(p.first > 0){
                pq.push(p);
            }
        }
        auto p =pq.top();
        if(p.first>=2){
            ans.push_back(p.second.second);
            ans.push_back(p.second.second);
            return ans;
        }
        while(p.first){
            ans.push_back(p.second.second);
            p.first--;
        }
        return ans;
    }
};