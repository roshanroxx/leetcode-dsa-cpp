//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // int n=triangle.size();
        int m= triangle[n-1].size();
        // int 
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                    continue;
                }
                if(j==i){
                    triangle[i][j]+=triangle[i-1][j-1];
                    continue;
                    
                }
                triangle[i][j]+=min(triangle[i-1][j], triangle[i-1][j-1]);
                
            }
        }
        // for(int )
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends