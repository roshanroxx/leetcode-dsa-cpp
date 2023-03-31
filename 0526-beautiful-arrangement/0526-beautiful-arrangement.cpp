class Solution {
public:

    bool check(int n,int i){
        return (n%i==0)||(i%n==0);
    }
    void pp(vector<int>& v,int& res,vector<bool>& bl){
        if(v.size()==bl.size()-1){
            res++;
            return;
        }
        // if(bl[])
        for(int i=1;i<bl.size();i++){
            if( bl[i]==false && check(i,v.size()+1)){
                bl[i] = true;
                v.push_back(i);
                pp(v,res,bl);
                bl[i]=false;
                v.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> bl(n+1,0);
        vector<int> v;
        int res=0;
        pp(v,res,bl);
        return res;
    }
};