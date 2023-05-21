//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i=0;i<m;i++){
        if(mp.find(a2[i])==mp.end()){
            mp.insert({a2[i],1});
        }
        else{
            mp.find(a2[i])->second++;
        }
    }
    // cout<<mp.size()<<" ";
    for(int i=0;i<n;i++){
        if(mp.find(a1[i])!=mp.end() ){
            auto itr = mp.find(a1[i]);
            itr->second--;
            // cout<<itr->first<<" ";
            if(itr->second==0){
                mp.erase(itr);
            }
        }
    }  
    // cout<<mp.size();
    if(mp.empty()) return "Yes";
    else {return "No";}
}