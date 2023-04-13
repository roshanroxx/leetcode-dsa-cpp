class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> s;
        for(;i<pushed.size();i++){
            s.push(pushed[i]);
            if(!s.empty() && s.top()==popped[j]){
                while(!s.empty() && s.top()==popped[j]){
                    s.pop();
                    j++;
                }
            }
        }
        while(!s.empty()){
            if(s.top()!=popped[j]){
                return false;
            }
            s.pop();
            j++;
        }
        return j==popped.size();
    }
};