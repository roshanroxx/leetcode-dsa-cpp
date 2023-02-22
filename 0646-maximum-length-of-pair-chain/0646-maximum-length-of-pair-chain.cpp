class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        for(int i =0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }
        sort(pairs.begin(),pairs.end());
        for(int i =0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }

        int count=1;
        int k=0;
        for(int i=1;i<pairs.size();i++){
            if(pairs[k][1]<pairs[i][0]){
                count++;
                k=i;
            }
            // if(pairs[k][0]==pairs[i][0]){
            //     if(pairs[k][1]>pairs[i][1]){
            //         k=i;
            //     }
            // }
        }
        // for(auto p:pairs){
        //     for(auto x:p){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        return count;
    }
};