/*
    Name: Halil Akca
    Assignment: 01 - Knights Tour
    CSCI 235 - Professor Zamansky

    This will place queens in a N*N board in such a way that no queen can take another queen in one move.
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void place(std::vector<std::string>& board, int row);
bool validness(std::vector<std::string> board, int row, int col);

std::vector<std::vector<std::string>> solutions;

std::vector<std::vector<std::string>> nqueensSolve(int n) 
{
    std::vector<std::string> board(n,std::string(n,'.'));
    
    place(board, 0);
    return solutions;
}

void place(std::vector<std::string>& board, int row)
{
    if(row==board.size())
    {
        solutions.push_back(board);
        return;
    }

    for(int i=0; i<board.size(); i++)
    {
        if(validness(board, row, i))
        {
            board[row][i] = 'Q';
            place(board, row+1);
            board[row][i] = '.';
        }
    }
}
    
bool validness(std::vector<std::string> board, int row, int col)
{
    for(int i=row; i>=0; i--)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    
    for(int i=row, j=col; i>=0 && j<board.size(); i--, j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int size = 9;
    if(size==0 || size==2 || size==3)
    {
        std::cout << "There is no legal configuration of queens with a " << size << "*" << size << " board!\n";
        return 0;
    }
    nqueensSolve(size);
    std::cout << "\nSize of board: " << size << "*" << size << "\n";
    for (auto it = solutions[0].begin(); it != solutions[0].end(); it++)
    {
        std::cout << *it << "\n";
    }
    std::cout << "\n";
    return 0;
}