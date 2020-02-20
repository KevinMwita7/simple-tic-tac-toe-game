#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class board {
public:
	board();// board default constructor
	board(int);
	char cell[3][3];
};
// where the game is handled
void game();
// confirms the validilty of the move made
bool make_play(board&, int, char);
char select_character();
// in case an error occurs, this is called and will only proceed if a legitimate value is called
int getCell();
// returns a true if winner is true
bool get_winner(board&,const char&);
// gets the computer play
int comp_play();
// gets the mark that the winner was using
char get_winner_mark(board&, char&, char&);