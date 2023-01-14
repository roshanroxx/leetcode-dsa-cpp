class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0)
        {
            for(int i=0;i<code.size();i++)
            {
                code[i] = 0;
            }
            return code;
        }
        else if(k>0)
        {
            int sum=0;
            vector<int> v;
            for(int i =0;i<k;i++)
            {
                sum  = sum +code[i];
            }
            for(int i=0;i<code.size();i++)
            {
                if(i+k<code.size())
                {
                    sum = sum - code[i] + code[i+k];
                    v.push_back(sum);
                }
                else{
                    sum = sum - code[i] + code[i+k-code.size()];
                    v.push_back(sum);
                }
            }
            return v;
        }
        else if(k<0)
        {
            int sum=0;
            // int t = -k;
            vector<int> v;
            for(int i =code.size()-1;i>code.size()-1+k;i--)
            {
                sum  = sum +code[i];
            }
            v.push_back(sum);
            for(int i=1;i<code.size();i++)
            {
                if(i+k<=0)
                {
                    sum = sum - code[code.size()-1+k+i] + code[i-1];
                    v.push_back(sum);
                }
                else{
                    cout<<sum;
                    sum = sum - code[i+k-1] + code[i-1];
                    v.push_back(sum);
                }
            }
            return v;
        }
        return code;

    }
};