class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        if(num>0){
            vector<int> v(10,0);
            while(num!=0){
                v[num%10]++;
                num= num/10;
            }
            string s="";
            for(int i=1;i<10;i++){
                if(v[i]!=0){
                    s.push_back(i+'0');
                    v[i]--;
                    break;
                }
            }
            for(int i=0;i<10;i++){
                while(v[i]!=0){
                    s.push_back(i+'0');
                    v[i]--;
                }
            }
            long long ans = stoll(s);
            return ans;
        }
        else{
            num = -1*num;
            vector<int> v(10,0);
            while(num!=0){
                v[num%10]++;
                num= num/10;
            }
            string s="";
            for(int i=9;i>=1;i--){
                if(v[i]!=0){
                    s.push_back(i+'0');
                    v[i]--;
                    break;
                }
            }
            for(int i=9;i>=0;i--){
                while(v[i]!=0){
                    s.push_back(i+'0');
                    v[i]--;
                }
            }
            long long ans = stoll(s);
            return ans*-1;
        }
        
    }
};