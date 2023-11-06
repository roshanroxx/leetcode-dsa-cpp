//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    int mod =1e9+7;
    
    
    long long power(int n,int r)
    {
       if(r==1) return (long long)n;
       
       if(r%2==0){
           long long k =power(n,r/2)%mod;
           k = (k*k)%mod;
           return k;
       }
       else{
           return (n*1LL*power(n,r-1))%mod;
       }
        
    }
    
    // 5^9 = 5 * 5^8;
    // 5^8 = 5^4 * 5^4;
    // 5^4 = 5^2 * 5^2;
    

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends