//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        int l,r,sum;
        for(int i=0;i<n;i++){
            sum=A[i];
            if(i==0){
                l=1;
            }else{
                l=0;
            }
            if(i==n-1){
                r=n-2;
            }else{
                r=n-1;
            }
            sum +=A[l];
            sum+=A[r];
            while(l<r){
                if(l==i){
                    sum-=A[l];
                    l++;
                    sum+=A[l]; 
                }
                if(r==i){
                    sum-=A[r];
                    r--;
                    sum+=A[r];
                }
                if(l==r){
                    break;
                }
                if(sum==X){
                    // cout<<l<<" "<<i<<" "<<r;
                    return 1;
                }
                else if(sum>X){
                    sum-=A[r];
                    r--;
                    sum+=A[r];
                }
                else{
                    sum-=A[l];
                    l++;
                    sum+=A[l];
                }
            }
        }
        return 0;
        
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends