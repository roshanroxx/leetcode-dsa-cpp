class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        for(int i=0;i<chars.size();){
            int ct= 0;
            char c = chars[i];
            while(i<chars.size() && c==chars[i]){
                ct++;
                i++;
            }
            s.push_back(c);
            if(ct>1){
                string l =to_string(ct);
                reverse(l.begin(),l.end());
                while(l.size()!=0){
                    s.push_back(l.back());
                    l.pop_back();
                }

            }
        }
        chars =s;
        return s.size();
    }
};