//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &v1, vector<int> &v2) {
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int m = k-1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(pq.size()<k){
                    pq.push(v1[i]+v2[j]);
                }
                else if(v1[i]+v2[j]>pq.top()){
                    pq.pop();
                    pq.push(v1[i]+v2[j]);
                }
                else{
                    break;
                }
            }
        }
        vector<int> v(k);
        while(!pq.empty()){
            v[m] = pq.top();
            pq.pop();
            m--;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends