#include "Command_Delete.h"

Command_Delete::Command_Delete(Board* board, int row, int col, int num)
{
	this->board = board;
	this->row = row;
	this->col = col;
	this->num = num;
}

void Command_Delete::execute()
{
	board->remove(row, col);
}

void Command_Delete::undo()
{
	board->fill(row, col, num);
}
