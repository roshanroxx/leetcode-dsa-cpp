class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int  i =0;
        int j = people.size()-1;
        int k=0;
        while(i<j){
            if(people[i] +people[j]<=limit){
                k+=1;
                i++;
                j--;
                // cout<<people[i]<<"  ";
            }
            else{
                k+=1;
                j--;
            }
        }
        if(i!=j){
            return k;
        }

        return k+1;
    }
};