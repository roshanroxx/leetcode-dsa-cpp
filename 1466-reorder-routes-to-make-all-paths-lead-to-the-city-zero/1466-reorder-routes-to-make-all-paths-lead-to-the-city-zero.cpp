class Solution {
public:

    int pp(vector<vector<int>>& v,int k,vector<bool>& vis,int &cnt){
        int m=0;
        if(k<0) k=k*-1;
        for(auto x :v[k]){
            if(vis[abs(x)]==0){
                vis[abs(x)]=1; 
                if(x>=0){
                    m = pp(v,x,vis,cnt);

                }
                else {
                    m = pp(v,-1*x,vis,cnt);

                }
                // cnt+=m;
                if(x>=0){
                    cnt++;
                }
            }
        }
        
        return 0;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> v(n);
        // vector<vector<int>> vd(n);
        for(auto i :connections){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(-1*i[0]);
            
        }
        for(auto p :v){
            for(auto l : p){
                cout<<l<<" ";
            }
            cout<<endl;
        }
        vector<bool > vis(n,0);
        // queue<int> q;
        // q.push(0);
        vis[0]=1;
        int cnt=0;
        int p =pp(v,0,vis,cnt);
        return cnt;
    }
};