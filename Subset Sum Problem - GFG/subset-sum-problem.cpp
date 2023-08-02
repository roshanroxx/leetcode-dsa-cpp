//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool memo(vector<int>& arr, int sum,int n,vector<vector<int>>& dp){
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(n==0) return 0;
        if(dp[sum][n]!=-1) return dp[sum][n];
        int nottake =  memo(arr,sum,n-1,dp);
        if(nottake==1) return 1;
        int take = memo(arr,sum-arr[n-1],n-1,dp);
        return dp[sum][n] = (nottake || take);
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(sum+1,vector<int>(arr.size()+1,-1));
        return memo(arr,sum,arr.size(),dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends