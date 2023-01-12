class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count=0;
        int ri,rj;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] =='R')
                {
                    ri=i;
                    rj=j;
                    break;
                }
            }
        }
        // cout<<ri<<" "<<rj;
        for(int i=rj;i<8;i++)
        {
            // cout<<board[ri][i]<<" ";
            if(board[ri][i]=='B' || board[ri][i]=='b')
            {
                break;
            }
            if(board[ri][i]=='p' || board[ri][i]=='P' )
            {
                // cout<<" hjb ";
                count++;
                break;
            }
        }
        for(int i=rj;i>=0;i--)
        {
            if(board[ri][i]=='B')
            {
                break;
            }
            if(board[ri][i]=='p' || board[ri][i]=='P' )
            {
                count++;
                break;
            }
        }
        for(int i=ri;i>=0;i--)
        {
            if(board[i][rj]=='B')
            {
                break;
            }
            if(board[i][rj]=='P' || board[i][rj] =='p')
            {
                count++;
                break;
            }
        }
        for(int i=ri;i<8;i++)
        {
            if(board[i][rj]=='B')
            {
                break;
            }
            if(board[i][rj]=='P' || board[i][rj] =='p')
            {
                count++;
                break;
            }
        }
        return count;
    }
};