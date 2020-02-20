#include "game.h"

board::board() { 
	// default constructor
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cell[i][j] = ' ';//initializes all cells in the array to chars
		}
	}
}

char select_character() {
	char mark;
	const char option1 = 'x';
	const char option2 = 'o';
	cout << "Choose between x or o: ";
	cin >> mark;
	if (mark == option1 || mark == option2) {
		cout << "You chose " << mark << "!\n";
		return mark;
	}
	else
		// call function again if player does not select either x or o
		select_character();
}

int getCell() {
	int cell_number = 0;
	cout << "Enter the cell you want to draw on: ";
	cin >> cell_number;
	if (cell_number > 9 || cell_number < 1) {
		cerr << "Cell must be be between 1 and 9! \n";
		getCell();
	}
	else
	return cell_number;
}

bool make_play(board& b, int x, char mark) {
	// confirms whether a cell in the board is free
	if (b.cell[0][0] == ' ' && x == 1)//cell 1
		b.cell[0][0] = mark;
	else if (b.cell[0][1] == ' ' && x == 2)//cell 2
		b.cell[0][1] = mark;
	else if (b.cell[0][2] == ' ' && x == 3)//cell 3
		b.cell[0][2] = mark;
	else if (b.cell[1][0] == ' ' && x == 4)//cell 4
		b.cell[1][0] = mark;
	else if (b.cell[1][1] == ' ' && x == 5)//cell 5
		b.cell[1][1] = mark;
	else if (b.cell[1][2] == ' ' && x == 6)//cell 6
		b.cell[1][2] = mark;
	else if (b.cell[2][0] == ' ' && x == 7)//cell 7
		b.cell[2][0] = mark;
	else if (b.cell[2][1] == ' ' && x ==8)//cell 8
		b.cell[2][1] = mark;
	else if (b.cell[2][2] == ' ' && x == 9)//cell 9
		b.cell[2][2] = mark;
	else {
		return false;
	}
	return true;
}

bool get_winner(board& b, const char& player_mark) {
	// TODO: pass on the players' marks later on to compare if adjacent cells are equal
	if (b.cell[0][0] == player_mark && b.cell[0][1] == player_mark && b.cell[0][2] == player_mark)
		return true;
	else if (b.cell[1][0] == player_mark &&  b.cell[1][1] == player_mark && b.cell[1][2] == player_mark)
		return true;
	else if (b.cell[2][0] == player_mark && b.cell[2][1] == player_mark && b.cell[2][2] == player_mark)
		return true;
	else if (b.cell[0][0] == player_mark && b.cell[1][0] == player_mark && b.cell[2][0] == player_mark)
		return true;
	else if (b.cell[0][1] == player_mark && b.cell[1][1] == player_mark && b.cell[2][1] == player_mark)
		return true;
	else if (b.cell[0][2] == player_mark && b.cell[1][2] == player_mark && b.cell[2][2] == player_mark)
		return true;
	else if (b.cell[0][0] == player_mark && b.cell[1][1] == player_mark && b.cell[2][2] == player_mark)
		return true;
	else if (b.cell[0][2] == player_mark && b.cell[1][1] == player_mark && b.cell[2][0] == player_mark)
		return true;
	else
		return false;
}

void game() {
	// creates a board
	board TTT;
	// Either x or o depending on user input 
	char player_mark = select_character();
	char comp_mark;
	if (player_mark == 'x')
	comp_mark = 'o';
	else comp_mark = 'x';
	int cell = 0;
	// gets the computer generated random number representing a cell
	int comp_turn;
	cout << "Cells are numbered from left to right with 1 been on the left topmost corner.\n";
	for (int i = 0; i < 3; ++i) {
		cout << "Enter the cell you want to draw on: ";
		cin >> cell;
		if (cell < 1 || cell>9) {
			cerr << "Cell must be between 1 and 9!\n";
			cell = getCell();
		}
		while (!make_play(TTT, cell, player_mark)) {
			cell = getCell();
		}
		make_play(TTT, cell, player_mark);

		// comp play
		comp_turn = comp_play();
		while (!make_play(TTT, comp_turn, comp_mark))
			comp_turn = comp_play();
		make_play(TTT, comp_turn, comp_mark);

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (j != 2)
					cout << TTT.cell[i][j] << " ";
				else
					cout << TTT.cell[i][j] << endl;
			}
		}

	}
	// check winner
	char winner;
	if (get_winner(TTT, player_mark)) {
		winner = get_winner_mark(TTT, player_mark, comp_mark);
		if (winner == player_mark)
			cout << "You won!\n";
		else if (winner == comp_mark)
			cout << "Computer won!\n";
	}
}
	
int comp_play() {
	int result;
	srand(time(NULL));
	int low = 1;
	int high = 9;
	result = rand() % (high - low) + low;
	return result;
}

char get_winner_mark(board&b, char& human, char& comp) {
	// check if human won
	if (b.cell[0][0] == human && b.cell[0][1] == human && b.cell[0][2] == human)
		return human;
	else if (b.cell[1][0] == human && b.cell[1][1] == human && b.cell[1][2] == human)
		return human;
	else if (b.cell[2][0] == human && b.cell[2][1] == human && b.cell[2][2] == human)
		return human;
	else if (b.cell[0][0] == human && b.cell[1][0] == human && b.cell[2][0] == human)
		return human;
	else if (b.cell[0][1] == human && b.cell[1][1] == human && b.cell[2][1] == human)
		return human;
	else if (b.cell[0][2] == human && b.cell[1][2] == human && b.cell[2][2] == human)
		return human;
	else if (b.cell[0][0] == human && b.cell[1][1] == human && b.cell[2][2] == human)
		return human;
	else if (b.cell[0][2] == human && b.cell[1][1] == human && b.cell[2][0] == human)
		return human;

	// check if comp won
	else if (b.cell[0][0] == comp && b.cell[0][1] == comp && b.cell[0][2] == comp)
		return comp;
	else if (b.cell[1][0] == comp && b.cell[1][1] == comp && b.cell[1][2] == comp)
		return comp;
	else if (b.cell[2][0] == comp && b.cell[2][1] == comp && b.cell[2][2] == comp)
		return comp;
	else if (b.cell[0][0] == comp && b.cell[1][0] == comp && b.cell[2][0] == comp)
		return comp;
	else if (b.cell[0][1] == comp && b.cell[1][1] == comp && b.cell[2][1] == comp)
		return comp;
	else if (b.cell[0][2] == comp && b.cell[1][2] == comp && b.cell[2][2] == comp)
		return comp;
	else if (b.cell[0][0] == comp && b.cell[1][1] == comp && b.cell[2][2] == comp)
		return comp;
	else if (b.cell[0][2] == comp && b.cell[1][1] == comp && b.cell[2][0] == comp)
		return comp;

}


