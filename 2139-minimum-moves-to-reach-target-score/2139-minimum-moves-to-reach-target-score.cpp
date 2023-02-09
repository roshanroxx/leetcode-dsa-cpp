class Solution {
public:
    int count=0;
    int maxd(int target,int m){
        // int count=0;
        while(m!=0 && target>1){
            if(target%2==0){
                target = target/2;
                count++;
                m--;
            }
            else{
                target--;
                count++;
            }
        }
        return target;
    }
    int minMoves(int target, int maxDoubles) {
        if(target==1){
            return count;
        }
        target = maxd(target,maxDoubles);
        cout<<target;
        if(target==1){
            return count;
        }
        else{
            return count+target-1;
        }
    }
};