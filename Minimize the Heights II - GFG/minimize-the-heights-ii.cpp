//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
       vector<int> v(n);
       for(int i=0;i<n;i++){
           v[i] = arr[i];
        //   cout<<v[i]<<" ";
       }
    //   cout<<endl;
       sort(v.begin(),v.end());
       
       int ans = v[n-1]-v[0];
       
       for(int i=0;i<n-1;i++){

           int a = v[0]+k;
           int b = v[i]+k;
           
           
           if(v[i+1]-k>=0) {
               a = min(a,v[i+1]-k);
               b = max(b,v[n-1]-k);
                ans = min(ans,abs(b-a));
           }
        //   if(v[n-1]-k>=0) 
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends