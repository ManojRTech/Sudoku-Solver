#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n) //O(n)
{
    for(int j=0;j<n;j++) //row check
    {
        if(board[row][j]=='Q')
        {
            return false;
        }
    }
    for(int i=0;i<n;i++) //column check
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) //left-diagonal check
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++) //right-diagonal check
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
void nQueens(vector<string> &board, int row, int n, vector<vector<string> > &ans) //O(n!), since row 1 - O(n)possibilities
{                                                                                        //since row 2 - O(n-1)possibilities
    if(row==n)                                                                           //since row 3 - O(n-2)possibilities
    {                                                                                    //since row 4 - O(n-3)possibilities ... and so on
        ans.push_back(board);                                                                                  
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,row,j,n))
        {
            board[row][j]='Q'; //placing queen
            nQueens(board,row+1,n,ans);
            board[row][j]='.'; //backtracking
        }
    }
}
int main()
{
    int n=4;
    vector<string> board(n, string(n,'.'));
    vector<vector<string>> ans;
    nQueens(board,0,n,ans);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}