//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int unset(int n,int k){
        int t =1;
        t = (t<<k);
        t = n&(~t);
        // cout<<t<<" ";
        return t;
        
    }

  public:
    int noConseBits(int n) {
        // code here
        for(int i=29;i>=0;i--){
            int t = (n>>i+2)&1;
            int t2 = (n>>i+1)&1;
            int t3 = (n>>i)&1;
            if(t && t2 && t3){
                n = unset(n,i);
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends