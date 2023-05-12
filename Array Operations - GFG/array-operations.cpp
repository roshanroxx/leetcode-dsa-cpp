//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int val=1;
        int cnt =0;
        int prev=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt++;
                if(prev!=0){
                    val++;
                }
                prev=0;
            }
            else{
                prev++;
                
            }
        }
        if(prev!=0){
            val++;
        }
        if(cnt==0){
            return -1;
        }
        if(val==1) return 0;
        return val-1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends