class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            auto it = m.find(s[i]);
            if(it!=m.end())
            {
                (*it).second++;
            }
            else{
                m.insert({s[i],1});    
            }
        }
        // for(const auto& [key,map] :m)
        // {
        //     cout<<key<<"  "<<map<<"  ";
        // }
        for(int i=0;i<t.size();i++)
        {
            auto it =m.find(t[i]);
            if(it==m.end())
            {
                return false;
            }
            else if(it!=m.end())
            {
                if((*it).second>1)
                {
                    (*it).second--;
                }
                else{
                    m.erase(it);
                }
            }
        }
        if(m.size()>0)
        {
            return false;
        }
        return true;
    }
};