#include "Game_Manager.h"

Game_Manager::Game_Manager()
{
	//string temp;
	//cout << "Welcome to Sudoku" << endl;
	//cout << "Please insert your name" << endl;
	//cin >> temp;
	//player.setName(temp);
	//cout << "Hi " << temp << " Press "

	int choose;
	bool condition = true;
	cout << "1. Start" << endl << "2. Exit" << endl;
	cin >> choose;
	while (condition)
	{
		cout << "Select your command: ";
		switch (choose)
		{
		case 1:
			play();
			condition = false;
			break;

		case 2:
			quit();
			condition = false;
			break;
		default:
			cout << "Invalid Option, try again" << endl;
		}

	}
}

void Game_Manager::fillCell(int row, int col, int num)
{	
	// create new command
	Commands* fill{};
	fill = new Command_Fill(&board, row, col, num);

	// Execute command
	fill->execute();

	// push command
	//undo.pushCommand(fill);
}

void Game_Manager::deleteCell(int row, int col)
{
	int temp = board.getNum(row, col);
	Commands* remove{};
	remove = new Command_Delete(&board, row, col, temp);

	remove->execute();

	//undo.pushCommand(remove);
}

bool Game_Manager::checkWin()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board.isValid(i, j, board.getNum(i, j)))
				return true;
		}
	}
	return false;
}

void Game_Manager::undoMove()
{
	Commands* a{};
	a = undo.popCommand();
	a->undo();
	redo.pushCommand(a);
}

void Game_Manager::redoMove()
{
	cout << "Redo Move" << endl;
	/*Commands* x{};
	x = redo.popCommand();
	x->execute();*/
}

void Game_Manager::quit()
{
	exit;
}

void Game_Manager::play()
{
	cout << "Starting Game" << endl;
}

int main()
{
	

	return 0;
}
