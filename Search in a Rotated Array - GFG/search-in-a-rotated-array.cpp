//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int x){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        int start =l,end =h;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[mid]==x){return mid;}
            if(arr[start]<=arr[mid])
            {
                if(x>=arr[start] && x<arr[mid]){end = mid-1;}
                else{start = mid+1;}
            }
            else{
                if(x>=arr[mid] && x<=arr[end]){start = mid+1;}
                else{end = mid -1;}
            }
        }
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends