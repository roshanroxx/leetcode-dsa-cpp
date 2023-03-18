class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,int> st;
        st["+"] =1;
        st["-"] =2;
        st["*"] =3;
        st["/"] =4;
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(st.find(tokens[i]) == st.end()){
                s.push(stoi(tokens[i]));
            }
            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                // int c =
                if(st[tokens[i]]==1){
                    int c = a+b;
                    s.push(c);
                    // s.push(to_string(c));
                }
                else if(st[tokens[i]]==2){
                    int c = a-b;
                    // s.push(to_string(c));
                    s.push(c);
                }
                if(st[tokens[i]]==3){
                    int c = a*b;
                    s.push(c);
                    // s.push(to_string(c));
                }
                if(st[tokens[i]]==4){
                    int c = a/b;
                    s.push(c);
                    // s.push(to_string(c));
                }

            }
        }
        return s.top();
    }
};