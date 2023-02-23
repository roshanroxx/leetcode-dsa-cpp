class Solution {
public:

    bool isp(char c){
        return (c=='(' || c==')');
    }
    bool isv(string s){
        int count = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return (count==0);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> v;
        unordered_set<string> visited;
        queue<string> q;
        string temp;
        bool level=false;
        int k;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            s=q.front();q.pop();
            if(isv(s)){
                if(level==false){
                    v.push_back(s);
                    k = s.size();
                    level =true;

                }
                else if(s.size()==k)
                {
                    v.push_back(s);

                }
                continue;
            }
            for(int i=0;i<s.size();i++){
                if(!isp(s[i])){
                    continue;
                }
                temp = s.substr(0,i)+s.substr(i+1);
                if(visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }


        return v;
    }
};