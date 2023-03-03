class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(n>haystack.size()){return -1;}
        for(int i=0;i<haystack.size()-n+1;i++){
            // cout<<i<<" l ";
            if(haystack[i]==needle[0]){
                // cout<<haystack.substr(i,i+n)<<" ";
                // if(needle == haystack.substr(i,i+n)){
                //     return i;
                // }
                // cout<<i<<" ";
                bool p =true;
                for(int j=0;j<n && i+j<haystack.size();j++){
                    if(haystack[i+j]!=needle[j]){
                        p = false;
                        // cout<<needle[j]<<" "<<haystack[j]<<" re ";
                        break;
                    }
                }
                // cout<<" k "<<p<<"  ";
                if(p==true){
                    return i;
                }
            }
        }
        return -1;
    }

    // bool check(const& needle, haystack)
};