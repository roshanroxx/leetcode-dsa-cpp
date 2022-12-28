class Solution {
public:
    bool isPalindrome(int x) {
        long long k=0;
        int p= x;
        bool m;
        if(x<0)
        {
            m=true;
            // x=0-x;
        }
        else{
            m = false;
        }
        while(x!=0)
        {
            k = k*10+x%10;
            x= x/10;
        }
        if(m==false)
        {
            return (k==p);
        }
        return(p==-k);
    }
};