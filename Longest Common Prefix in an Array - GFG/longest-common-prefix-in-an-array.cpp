//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string k=*min_element(arr,arr+N);
        int m = k.length();
        string ans="";
        for(int i=0;i<m;i++){
            char c =k[i];
            bool b = true;
            for(int j=0;j<N;j++){
                if(arr[j][i]!=c){
                    b=false;
                }
            }
            if(b==true){
                ans.push_back(k[i]);
            }
            else{
                if(ans.size()==0){
                    return "-1";
                }
                return ans;
            }
        }
        if(ans.size()==0){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends