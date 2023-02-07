class Solution {
public:
    bool isValid(string l) {
        stack<char> s;
        for(char p:l){
            if(p=='a'){
                s.push(p);
            }
            else if(p=='b'){
                s.push(p);
            }
            else if(p=='c'){
                if(s.size()<2){
                    return false;
                }
                if(s.top()=='b'){
                    s.pop();
                }
                else{
                    return false;
                }
                if(s.top()=='a'){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        return s.empty();
    }
};