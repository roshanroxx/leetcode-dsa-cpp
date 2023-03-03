//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long int r = L;
        long long int s = B;
        while(r!=s){
            if(r>s){
                r=r-s;
            }
            else{
                s=s-r;
            }
        }
        s = L/r;
        long long int t = B/r;
        s = s*t;
        vector<long long int> v;
        v.push_back(s);
        v.push_back(r);
        return v;
    }
    // 87568608564 76549893472
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends