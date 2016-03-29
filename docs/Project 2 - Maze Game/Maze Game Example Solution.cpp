
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 20;
const int BOARD_DEPTH = 3;

const char WALL = '-';
const char UP = 'U';
const char DOWN = 'D';
const char GOAL = 'G';
const char PLAYER = 'P';
const char DEFAULT = '.';

void displayBoard(char[][BOARD_WIDTH][BOARD_HEIGHT],int,int,int);
bool inputBoard(char[][BOARD_WIDTH][BOARD_HEIGHT],char[],int&,int&,int&);
bool move(char[][BOARD_WIDTH][BOARD_HEIGHT],int&,int&,int&,int,int);

int main() {

	char fileName[30];
	char board[BOARD_DEPTH][BOARD_HEIGHT][BOARD_HEIGHT];

	bool playing = true , win = false;
	char input;
	int x, y, z;

	do {
		system("cls");

		cout << endl
			 << "   Maze Game" << endl
			 << "   =========" << endl << endl
			 << "   Enter file name: ";

		cin >> fileName;

	} while(!inputBoard(board,fileName,x,y,z));

	while(playing) {
		displayBoard(board,x,y,z);
		input = _getch();

		switch(input) {
			case 27: //The escape char
				playing = false;
				break;
			case 'w':
				win = move(board,x,y,z,-1,0);
				break;
			case 's':
				win = move(board,x,y,z,1,0);
				break;
			case 'a':
				win = move(board,x,y,z,0,-1);
				break;
			case 'd':
				win = move(board,x,y,z,0,1);
				break;
		}

		if(win) {
			system("cls");
			cout << endl << "   You win!" << endl
				 << endl << "   ";
			system("pause");
			playing = false;
		}
	}

	return 0;
}

bool inputBoard(char board[][BOARD_WIDTH][BOARD_HEIGHT],char fileName[],int &x, int &y, int &z) {
	ifstream fin(fileName);

	for(int i = 0; i < BOARD_DEPTH; i++) 
		for(int j = 0; j < BOARD_WIDTH; j++) 
			for(int k = 0; k < BOARD_HEIGHT; k++) {
				fin >> board[i][j][k];
				if(board[i][j][k] == PLAYER) {
					x = j;
					y = k;
					z = i;
					board[i][j][k] = DEFAULT;
				}
			}

	return fin.good();
}

void displayBoard(char board[][BOARD_WIDTH][BOARD_HEIGHT], int x, int y, int z) {

	system("cls");

	for(int i = 0; i < BOARD_WIDTH; i++) {
		for(int j = 0; j < BOARD_HEIGHT; j++) {
			if(i == x && j == y)
				cout << PLAYER;
			else
				cout << board[z][i][j];
		}
		cout << endl;
	}
}

bool move(char board[][BOARD_WIDTH][BOARD_HEIGHT],int &x,int &y,int &z,int dx,int dy) {
	if(x + dx >= 0 && x + dx < BOARD_WIDTH && y + dy >= 0 && y + dy < BOARD_HEIGHT) {
		switch(board[z][x + dx][y + dy]) {
			case WALL:
				break;
			case UP:
				z++;
				break;
			case DOWN:
				z--;
				break;
			case GOAL:
				return true;
				break;
			case DEFAULT:
				x += dx;
				y += dy;
				break;
		}
	}

	return false;
}
