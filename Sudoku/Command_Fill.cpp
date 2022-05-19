#include "Command_Fill.h"

void Command_Fill::execute()
{
	board->fill(row, col, num);
}

void Command_Fill::undo()
{
	board->remove(row,col);
}

Command_Fill::Command_Fill(Board* board, int row, int col, int num)
{
	this->board = board;
	this->row = row;
	this->col = col;
	this->num = num;
}
