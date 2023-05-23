//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    if(n<2){
	        return 0;
	    }
	    sort(arr,arr+n);
	   // for(int i=0;i<n;i++){
	   // }
	    for(int i=0;i<n;i++){
	        arr[i]*=arr[i];
	        int c=arr[i];
	        int a =0;int b=i-1;
	        while(a<b){
	            if(c==arr[a]+arr[b]){
	                return 1;
	            }
	            else if(c>arr[a]+arr[b]){
	                a++;
	            }
	            else{
	                b--;
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends