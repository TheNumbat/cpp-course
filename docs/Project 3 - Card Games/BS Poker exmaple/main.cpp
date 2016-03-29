
#include "game.h"

using namespace std;

int welcome();

int main(int argc, char** argv) {

	//Display the starting menu and get the number of players
	int numP = welcome();

	//Create a "game" instance with the number of players
	game state(numP);
	
	//Run the game initialize function
	state.init();
	
	//Run the game loop function. This contains all the actual game logic.
	state.gameLoop();
	
	//End program
	return 0;
}

int welcome() {
	int input;
	do {
		//Output welcome screen
		system("cls");
	
		cout << endl << endl
			 << "      Welcome to BS Poker" << endl
			 << "      ===================" << endl << endl
			 << "      Enter number of players: ";
		
		//Input number of players
		cin >> input;
		
		//Only accept less than 13 players
		if(input > 13) {
			cout << endl << "      Too many players!" << endl << endl << "      ";
			system("pause");
		} else if(input < 2) {
			cout << endl << "      Too few players!" << endl << endl << "      ";
			system("pause");
		}
	//Repeat the welcome until the user enters less than 13 players
	} while(input > 13 || input < 2);
	
	//Output how many cards the users will be playing to -- either split up half the deck or take a maximum of 5 cards
	cout << endl << "      You will be playing up to " << (26 / input > 5 ? 5 : 26 / input) << " cards." << endl;
	cout << endl << "      ";
	system("pause");
	//Return number of players
	return input;
}

