//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum=0;
        int size =0;
        int p=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>x){
                while(sum>x){
                    sum-=arr[j++];
                }
                p = min(p,i-j+2);
            }
            
        }
        return p;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends