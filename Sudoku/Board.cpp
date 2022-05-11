#include "Board.h"

int Board::randomGenerator(int num)
{
    int random;
    
    random = rand() % num + 1;

    return random;
}

void Board::fillRegion(int row, int col)
{
    int num;
    for (int i = 0; i < 3; i++) // row
    {
        cout << "row " << i << endl;
        for (int j = 0; j < 3; j++) // column
        {
            cout << "col " << j << endl;
            //do
            //{
            //    num = randomGenerator(9);
            //    cout << num << endl;
            //    if (cekRegion(row, col, num))
            //        cout << "Ok" << endl;

            //} while (!isValid(row,col,num));

            while (true)
            {
                num = randomGenerator(9);
                if (isValid(row, col, num))
                {
                    fill(row + i, col + j, num);
                    cout << num << endl;
                    if (isValid(row, col, num))
                        cout << "Ok" << endl;
                    break;
                }
            }
            //fill(row + i, col + j, num);
        }
    }
}

Board::Board()
{
    srand(time(0));
    for (int i = 0; i < 9; i++) // init board with 0
    {
        for (int j = 0; j < 9; j++)
        {
            fill(i, j, 0);
        }
    }

    generateNumber();
}

void Board::generateNumber()
{
    // fill diagonal
    for (int i = 0; i < 9; i += 3)   // iterating through diagonal region
    {
        cout << "Region " << i << " , " << i << endl;
        fillRegion(i, i);
    }

    // fill remaining blocks
    //int num, cekCount = 0;
    //for (int i = 0; i < 9; i++)
    //{
    //    for (int j = 0; j < 9; j++)
    //    {
    //        if (board[i][j] == 0)
    //        {
    //            num = randomGenerator(9);
    //            fill(i, j, num);
    //        }
    //    }
    //}

    // remove number in block randomly
}

bool Board::cekRegion(int rowStart, int colStart, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[rowStart + i][colStart + i] == num)
            {
                cout << "there is same number in the region" << endl;
                return false;
            }
        }
    }
    return true;
}

bool Board::cekRow(int row, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
            return false;
    }
    return true;
    
}

bool Board::cekColumn(int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }
    return true;
}

bool Board::isValid(int row, int col, int num)
{
    return (cekColumn(col, num) && cekRow(row, num) && cekRegion(row-row%3, col-col%3, num));
}

void Board::fill(int row, int col, int num)
{
    board[row][col] = num;
}

void Board::remove(int row, int col)
{
    board[row][col] = 0;
}

void Board::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    Board board;

    board.printBoard();
    
}