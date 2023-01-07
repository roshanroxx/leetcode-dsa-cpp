class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(char c:t)
        {
            if(m.find(c)!=m.end())
            {
                auto it =m.find(c);
                (*it).second++;
            }
            else{
                m.insert({c,0});
            }
        }
        // for(const auto&[key,map]:m)
        // {
        //     cout<<key<<"  : "<<map<<endl;
        // }
        char k;
        for(char c :s)
        {
            auto it =m.find(c);
            if(it==m.end())
            {
                return (*it).first;
            }
            if((*it).second>0)
            {
                (*it).second--;
            }
            else if((*it).second==0)
            {
                m.erase(it);
            }

        }
        if(m.size()==1)
        {
            return (*m.begin()).first;
        }

        return k;
    }
};