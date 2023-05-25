//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int ptr=0,dis=0;
       int stp=0,cgas=0;
       for(int i=0;i<n;i++){
           ptr+=p[i].petrol;
           dis+=p[i].distance;
           cgas += p[i].petrol - p[i].distance;
        //   cout<<cgas<<" ";
           if(cgas<0){
               stp=i+1;
               cgas=0;
           }
       }
    //   cout<<ptr<<" "<<dis<<" p ";
       if(ptr<dis){
           return -1;
       }
       return stp;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends