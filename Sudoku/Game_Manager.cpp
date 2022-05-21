#include "Game_Manager.h"

Game_Manager::Game_Manager()
{
	string temp;
	cout << "Welcome to Sudoku" << endl;
	cout << "Please insert your name" << endl;
	cin >> temp;
	player.setName(temp);
	cout << "Hi " << temp << " Press " << endl;

	int choose;
	bool condition = true;
	cout << "1. Start" << endl << "2. Exit" << endl;

	// Main Menu
	while (condition)
	{
		cout << "Select your command: ";
		cin >> choose;
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
			break;
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
	undo.pushCommand(fill);
}

void Game_Manager::deleteCell(int row, int col)
{
	int temp = board.getNum(row, col);
	Commands* remove{};
	remove = new Command_Delete(&board, row, col, temp);

	remove->execute();

	undo.pushCommand(remove);
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
	Commands* x{};
	x = redo.popCommand();
	x->execute();
}

void Game_Manager::quit()
{
	cout << "Exiting...." << endl;
	exit;
}

void Game_Manager::play()
{
	cout << "Starting Game" << endl;
}

void Game_Manager::move()
{
	board.printBoard();
	bool condition = true;
	int opt;
	while (condition)
	{
		cout << "1. Fill" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Undo" << endl;
		cout << "4. Redo" << endl;
		cout << "5. Exit" << endl;
		cout << "Select your command: ";

		cin >> opt;
		switch (opt)
		{
		case 1:
			// Fill
			int row, col, num;
			cout << "Input Row, Column, and Value in sequence. Separate it with space ";
			cin >> row; cin >> col; cin >> num;
			fillCell(row, col, num);
			condition = false;
			break;

		case 2:
			// Delete
			int delRow, delCol;
			cout << "Input Row and Column in sequence. Separate it with space " << endl;
			cin >> delRow; cin >> delCol;
			deleteCell(delRow, delCol);
			condition = false;
			break;
		case 3:
			// Undo
			undoMove();
			condition = false;
			break;
		case 4:
			// Redo
			redoMove();
			condition = false;
			break;
		case 5:
			// Quit
			cout << "Quit" << endl;
			condition = false;
			exit(1);
			break;
		default:
			cout << "Invalid Option, try again" << endl;
			break;
		}
	}
}

int main()
{
	Game_Manager GM;

	while (!GM.checkWin())
	{
		GM.move();
	}

	return 0;
}
