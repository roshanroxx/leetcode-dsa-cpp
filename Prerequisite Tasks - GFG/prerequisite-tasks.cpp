//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> indeg(N,0);
	    int n =pre.size();
	    for(int i=0;i<n;i++){
	        indeg[pre[i].first] +=1;
	    }
        vector<vector<int>> vis(N);
        for(auto it : pre){
            vis[it.second].push_back(it.first);
        }
	    queue<int> s;
	    vector<int> v;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            s.push(i);
	            v.push_back(i);
	        }
	    }
	    while(!s.empty()){
	        int k = s.front();
	        s.pop();
	        for(int i:vis[k]){
	            indeg[i]-=1;
	            if(indeg[i]==0){
	                s.push(i);
	                v.push_back(i);
	            }
	           // if(k==pre[i].second){
	               // indeg[pre[i].first]-=1;
        	       // if(indeg[pre[i].first]==0){
        	       //     s.push(pre[i].first);
        	       //     v.push_back(pre[i].first);
        	       // }
	           // }
	        }
	    }
	    return (v.size()==N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends