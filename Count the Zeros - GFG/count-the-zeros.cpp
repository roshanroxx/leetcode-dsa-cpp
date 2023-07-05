//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int l(int arr[],int n,int x){
        int l =0;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(arr[mid]==x){
               ans =mid;
               l=mid+1;
            }
            else if(arr[mid]<x){
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
        return ans;
    }
    int countZeroes(int arr[], int n) {
        int k = l(arr,n,1);
        // if(k==-1){
        //     return n;
        // }
        // cout<<k<<" ";
        return n-k-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends