//Sudoku-Backtracking
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>>& board, int row, int col, char digit)
{
    for(int j=0;j<9;j++) //row check
    {
        if(board[row][j]==digit)
        {
            return false;
        }
    }
    for(int i=0;i<9;i++) //col check
    {
        if(board[i][col]==digit)
        {
            return false;
        }
    }
    int srow=(row/3)*3;
    int scol=(col/3)*3;
    for(int i=srow;i<=srow+2;i++) // 3x3 grid or box check
    {
        for(int j=scol;j<=scol+2;j++)
        {
            if(board[i][j]==digit)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku(vector<vector<char>>& board, int row, int col) // O(9^emptyCells) - since 9 choices for each cell
{
    if(row==9)
    {
        return true;
    }
    int nextRow=row, nextCol=col+1;
    if(col==9)
    {
        nextRow=row+1;
        nextCol=0;
    }
    if(board[row][col]!='.')
    {
        return sudoku(board,nextRow,nextCol);
    }
    for(char digit='1';digit<='9';digit++)
    {
        if(isSafe(board,row,col,digit))
        {
            board[row][col]=digit;
            if(sudoku(board,nextRow,nextCol))
            {
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}
int main()
{
    int n=9;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    sudoku(board, 0, 0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}