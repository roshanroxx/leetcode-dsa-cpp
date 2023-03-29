class Solution {
public:
    int minFlips(string target) {
        int count=target[0]-'0';
        
        for(int i=0;i<target.size()-1;i++){
            // while(i+1<target.size() && target[i]==target[i+1]){
            //     i++;
            // }
            if(target[i]!=target[i+1]){
                count++;

            }
        }
        return count;
    }
};