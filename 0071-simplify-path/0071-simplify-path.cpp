class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        stack<string> s;
        string x="";
        for(int i=1;i<path.size();i++){
            if(path[i]=='/'){
                if(x==""){
                    continue;
                }
                else if(x==".."){
                    if(!s.empty()){
                        s.pop();
                    }
                    x="";
                }
                else if(x=="."){
                    x="";
                }
                else{
                    s.push(x);
                    x="";
                }
            }
            else{
                x +=path[i];
            }
        }
        string ans="";
        while(!s.empty()){
            ans=s.top() +'/' + ans;
            // ans.push_back('/');
            s.pop();
        }
        ans = '/'+ans;
        if(ans.size()>1){
            ans.pop_back();
            return ans;
        }
        return ans;
    }
};