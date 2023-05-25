//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int step,max_reach,jump;
        jump=1;
        step=arr[0];
        max_reach=arr[0];
        for(int i=1;i<n-1;i++){
            if(i+arr[i]>max_reach){
                max_reach = i+arr[i];
            }
            step--;
            if(step==0){
                jump+=1;
                step = max_reach -i;
            }
            if(step<=0){
                return -1;
            }
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends