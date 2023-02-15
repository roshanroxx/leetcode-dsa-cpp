class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // string s="";
        vector<int> v;
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            carry+=k%10;
            k=k/10;
            carry+=num[i];
            v.push_back(carry%10);
            carry = carry/10;
        }
        while(k>0){
            carry+=k%10;
            k=k/10;
            v.push_back(carry%10);
            carry = carry/10;
        }
        while(carry>0){
            v.push_back(carry%10);
            carry = carry/10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};