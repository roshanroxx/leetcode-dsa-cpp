//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  
    long long sqrtt(long long x)
    {
        long long start =0,end =x;
        while(start<=end)
        {
            long long mid = (start+end)/2;
            if(mid*mid == x)
            {
                return mid;
            }
            else if (mid*mid >x)
            {
                end = mid-1;
            }
            else if (mid*mid<x)
            {
                if ((mid+1)*(mid+1)>x)
                { return mid;}
                start = mid+1; 
            }    
        }
        return -1;
    }
    long long int floorSqrt(long long int x) 
    {
       return sqrtt(x);  
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends