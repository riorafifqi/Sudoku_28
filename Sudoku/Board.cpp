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
        cout << "row " << i << endl;
        for (int j = 0; j < 3; j++) // column
        {
            cout << "col " << j << endl;

            while (true)
            {
                num = randomGenerator(9);
                cout << num << endl;
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

bool Board::fillRest(int row, int col)
{
    // Check if we have reached the 8th
    // row and 9th column (0
    // indexed matrix) , we are
    // returning true to avoid
    // further backtracking
    if (row == 8 && col == 9)
        return true;

    // Check if column value  becomes 9 ,
    // we move to next row and
    //  column start from 0
    if (col == 9) {
        row++;
        col = 0;
    }

    // Check if the current position of
    // the grid already contains
    // value >0, we iterate for next column
    if (board[row][col] > 0)
        return fillRest(row, col + 1);

    for (int num = 1; num <= 9; num++)
    {

        // Check if it is safe to place
        // the num (1-9)  in the
        // given row ,col  ->we
        // move to next column
        if (isValid(row, col, num))
        {

            /* Assigning the num in
               the current (row,col)
               position of the grid
               and assuming our assigned
               num in the position
               is correct     */
            board[row][col] = num;

            //  Checking for next possibility with next
            //  column
            if (fillRest(row, col + 1))
                return true;
        }

        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for
        // next assumption with
        // diff num value
        board[row][col] = 0;
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
        cout << "Region " << i << " , " << i << endl;
        fillRegion(i, i);
    }

    // fill remaining blocks
    fillRest(0, 0);

    // remove number in block randomly
    int count = 20; // Number of removed block
    while (count != 0)
    {
        int blockId = randomGenerator(81) - 1;

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

int main()
{

    Board board;

    board.printBoard();
    
}