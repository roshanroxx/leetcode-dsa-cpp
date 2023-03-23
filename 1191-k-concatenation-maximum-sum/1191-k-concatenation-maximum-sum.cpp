class Solution {
public:
    int base = (int)1e9 +7;
    vector<int> kadane(vector<int>& v, int k){
        int s=0,summ=0,ans=0;
        for(int i=0;i<v.size()*k;i++){
            if(i<v.size()){
                s = s+v[i% v.size()];
            }
            summ = summ+v[i%v.size()];
            ans = max(summ,ans);
            if(summ<0){
                summ =0;
            }
        }
        return {ans,s};
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<int> v;
        int sum =0;
        // int plo=0;
        for(int i=0;i<arr.size();){
            // plo+=arr[i];
            if(arr[i]>=0){
                while(i <arr.size() && arr[i]>=0){
                    sum = sum +arr[i];
                    i++;
                }
            }
            else {
                while(i <arr.size() && arr[i]<0){
                    sum = sum +arr[i];
                    i++;
                }
            }
            v.push_back(sum);
            sum=0;
        }
        // for(auto p :v){
        //     cout<<p<<" ";
        // }
        // if(v.size()==1){
        //     if(v[0]>=0){
        //         return (v[0]*(k))%base;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        long long summ =0;
        // long long s=0,ans =0;
        
        // for(int i=0;i<arr.size()*2;i++){
           
        //     // if()
        // }
        // cout<<summ<<" "<<ans<<" "<<s;
        if(k==1){
            return max(0,kadane(v,1)[0]);
        }
        else{
            auto p = kadane(v,2);
            // p[1] = p[1]/2;
            if(p[1]<=0){
                return p[0]%base;
            }
            for(int i=0;i<k-2;i++){
                summ = (summ%base + p[1]%base)%base;
            }
            summ = (summ +p[0])%base;
            return max(0,(int)summ);
        }
        return 0;
    }
};