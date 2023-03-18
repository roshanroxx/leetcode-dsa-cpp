class Solution {
public:
    double positive(double x, int n){
        if(n==0)return 1;
        else if(n%2==0){
            double temp = positive(x,n/2);
            return temp* temp;
        }
        else {
            double temp = positive(x,n-1);
            return temp*x;
        }
    }
    double negative(double x, int n){
        // cout<<n<<" "<<n%2<<" p ";
        if(n==0)return 1;
        else if(n%2==0){
            double temp = negative(x,n/2);
            return temp* temp;
        }
        else {
            double temp = negative(x,n+1);
            return temp*(1/x);
        }
    }
    double myPow(double x, int n) {
        if(n>=0){
            return positive(x,n);
        }
        else{
            return negative(x,n);
        }
    }
};
//TLE solution
        // double k = 1.0;
        // if(n==0) return 1;
        // else if(n>0){
        //     while(n!=0){
        //         k =k* n;
        //         n-=1; 
        //     }
        //     return k;
        // }
        // else {
        //     while(n!=0){
        //         k =k/ n;
        //         n-=1; 
        //     }
        //     return k;
        // }