#include "Board.h"

int Board::randomGenerator(int num)
{
    int random;
    
    random = rand() % num + 1;

    return random;
}

void Board::fillRegion(int row, int col)
{
    int num = 0;
    for (int i = 0; i < 3; i++) // row
    {
        //cout << "row " << i << endl;
        for (int j = 0; j < 3; j++) // column
        {
            //cout << "col " << j << endl;

            while (true)
            {
                num = randomGenerator(9);
                //cout << num << endl;
                if (cekRegion(row, col, num))
                {
                    {
                        fill(row + i, col + j, num);
                        break;
                    }
                }
            }
        }
    }
}

bool Board::fillRest()
{
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!findEmpty(row, col))
        // success!
        return true;

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // Check if looks promising
        if (isValid(row, col, num))
        {
            // Make tentative assignment
            board[row][col] = num;

            // Return, if success
            if (fillRest())
                return true;

            // Failure, unmake & try again
            board[row][col] = 0;
        }
    }

    // This triggers backtracking
    return false;
}

bool Board::findEmpty(int& row, int& col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {

                return true;
            }
                
        }
    }
    return false;
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
        //cout << "Region " << i << " , " << i << endl;
        fillRegion(i, i);
    }

    // fill remaining blocks
    fillRest();

    // remove number in block randomly
    int count = 20; // Number of removed block
    while (count != 0)
    {
        int blockId = randomGenerator(81) - 1;
        //cout << blockId << endl;
        // extract coordinates i  and j
        int i = blockId / 9;
        int j = blockId % 9;

        if (board[i][j] != 0)
        {
            count--;
            board[i][j] = 0;
        }
    }
}

bool Board::cekRegion(int rowStart, int colStart, int num)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[rowStart + i][colStart + j] == num)
                return false;

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

int Board::getNum(int row, int col)
{
    return board[row][col];
}

//int main()
//{
//    Board board;
//    
//}