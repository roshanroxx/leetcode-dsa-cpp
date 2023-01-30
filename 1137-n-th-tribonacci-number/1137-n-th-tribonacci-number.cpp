class Solution {
public:

    int pp(vector<int>& v,int n,int l){
        if(l==n){
            return v[l-1]+v[l-2]+v[l-3];
        }
        v[l] =v[l-1]+v[l-2]+v[l-3];
        return pp(v,n,l+1);

    }
    int tribonacci(int n) {
        if(n==0 || n==1){return n;}
        if(n==2){return 1;}
        vector<int> v(n);
        v[0]=0;v[1]=1;v[2]=1;
        return pp(v,n,3);
    }
};