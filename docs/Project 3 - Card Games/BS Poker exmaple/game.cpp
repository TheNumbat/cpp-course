
#include "game.h"
#include <fstream>
#include <conio.h>
#include <cstring>

//Paramterized constructor -- the ": highest" part means to call the constructor
//of the "highest" data member with the specified values
game::game(int numPlayers) : highest(NONE,0,0) {
	//Set up data values
	numP = numPlayers;
	players = new player[numP];
	//Intialize players with specified number of cards -- see comment in main.cpp
	for(int i = 0; i < numP; i++)
		players[i].init(26 / numPlayers > 5 ? 5 : 26 / numPlayers);
}

//Desctrutor
game::~game() {
	//Free player memory
	delete[] players;
}
	
//Intialize game
void game::init() {
	//Open "Cards.txt" file
	ifstream fin("cards.txt");
	//Input and shuffle deck
	cards.input(fin);
	cards.shuffle();
	system("cls");
}	

//Deal player hands
void game::dealHands() {
	//Shuffle the deck
	cards.shuffle();
	//Loop through players
	for(int i = 0; i < numP; i++) {
		//If the player is sitll in the game
		if(players[i].playing) {
			//Loop through the player's hand
			for(int j = 0; j < players[i].cards; j++) {
				//Copy card delt from deck to player hand
				cards.deal().copyTo(players[i].hand[j]);
			}
		}
	}
}

//Check if the highest call is actually there or not
bool game::checkHighest() {
	//Set up temporary data
	bool result = false;
	int numCards = 0, numCards2 = 0;
	bool seen[5] = {};
	
	//For each player, while we haven't found the hand
	for(int i = 0; !result && i < numP; i++) {
		//If the player is in the game
		if(players[i].playing) {
			//Loop through their hand
			for(int j = 0; !result && j < players[i].cards; j++) {
				//Retrive the card's value
				int val = players[i].hand[j].getValue();
				char* suit = players[i].hand[j].getSuit();
				
				//Switch on the type of hand of the highest call because different hands require
				//different conditions
				switch((int)highest.lvl) {
					//High card: if one is there, the hand is there
					case HIGH_CARD - 1:
						if(val == highest.v1.getValue()) 
							result = true;
						break;
					//Pair: if two are there, the hand is there
					case PAIR - 1:
						if(val == highest.v1.getValue())
							numCards++;
						if(numCards >= 2)
							result = true;
						break;
					//Three of a kind: if three are there, the hand is there
					case TRIPLE - 1:
						if(val == highest.v1.getValue())
							numCards++;
						if(numCards >= 3)
							result = true;
						break;
					//Foru of a kind: if four are there, the hand is there
					case QUAD - 1:
						if(val == highest.v1.getValue())
							numCards++;
						if(numCards >= 4)
							result = true;
						break;
					//Two pair: if two of both cards are there, the hand is there
					case TWO_PAIR - 1:
						if(val == highest.v1.getValue())
							numCards++;
						if(val == highest.v2.getValue())
							numCards2++;
						if(numCards >= 2 && numCards2 >= 2)
							result = true;
						break;
					//Straight: if all cards between (and including) the two cards are there, the hand is there
					case STRAIGHT - 1:
						if(val >= highest.v1.getValue() && val <= highest.v2.getValue()) {
							if(!seen[highest.v2.getValue() - val]) {
								numCards++;
								seen[highest.v2.getValue() - val] = true;
							}
						}
						if(numCards >= 5)
							result = true;
						break;
					//Striaght flush: same as straight, but all suits have to be the same
					case STRAIGHT_FLUSH - 1:
						if(val >= highest.v1.getValue() && val <= highest.v2.getValue() && strcmp(suit,highest.v1.getSuit()) == 0) {
							if(!seen[highest.v2.getValue() - val]) {
								numCards++;
								seen[highest.v2.getValue() - val] = true;
							}
						}
						if(numCards >= 5)
							result = true;
						break;
					//Full hosue: if three of the top card and two of the bottom card are there, the hand is there
					case FULL_HOUSE - 1:
						if(val == highest.v1.getValue())
							numCards++;
						if(val == highest.v2.getValue())
							numCards2++;
						if(numCards >= 2 && numCards2 >= 3)
							result = true;
						break;
				}
			}
		}
	}
	
	//Return if the hand is there or not
	return result;
}

void game::gameLoop() {
	//Set up temporary varaibles
	int round = 1;
	int starting = 0;
	bool roundControl;
	bool playing = true;
	
	//Actual game loop
	while(playing) {
		//Deal player hands
		dealHands();
		
		//Set up highest call to nothing
		highest.lvl = NONE;
		highest.v1.setValue(0,true);
		highest.v2.setValue(0,true);
		
		//Set up more temporary variables for the round
		bool first = true;
		int offset = 0;
		
		//Round loop
		roundControl = true;
		while(roundControl) {
			
			//For each player
			for(int i = starting; roundControl; ++i %= numP) {
			//If the player is still in the game
			if(players[i].playing) {
		
				//Input their call level
			
				bool selecting = true;
				int selection = highest.lvl + offset;		
				do {
					system("cls");
					
					//Output round number
					cout << endl << endl << "      ROUND " << round << endl
						 << "      =======" << (round > 9 ? "=" : "") << endl;
		
					//Output the player's hand
					cout << endl << "      Player " << i + 1 << " hand: " << endl;
					players[i].printHand();
	
					//IF they are not the first call, output the previous high call
					if(!first) {
						cout << endl << "      Previous call: ";
						highest.print();
						
					}
		
					cout << endl << "      Enter call level:" << endl;
					//Output the avaliable levels of hands 
					for(int j = highest.lvl + offset; j < TOTAL_HANDS; j++) {
						if(j == selection)
							cout << "   >  ";
						else
							cout << "      ";
						if(j != TOTAL_HANDS - 1)
							cout << hand_names[j] << endl;
						//Add BS as the final option, if you are not the first player to go
						else if(!first)
							cout << "BS!" << endl;
					}
					
					//Input the next key the user presses
					char key = _getch();
					//Up arrow: move the selection upward
					if(key == 72) {
						if(selection - offset > highest.lvl) selection--;
					//Down arrow: move the selection downward
					} else if(key == 80) {
						if(selection < (TOTAL_HANDS - (first ? 2 : 1))) selection++;
					//Enter: confirm selection
					} else if(key == '\r') {
						selecting = false;
					}
					
				//Repleat until the user presses enter
				} while(selecting);
				
				//No longer the first player
				first = false;
				
				//If the player selected BS
				if(selection == TOTAL_HANDS - 1) {
					
					//Output the BS screen
					
					system("cls");
					cout << endl << endl << "      Player " << i + 1 << " has called BS!" << endl << endl;
					cout << "      Cards:" << endl;
					//Output all cards of playing players
					for(int j = 0; j < numP; j++) {
						if(players[j].playing) {
							players[j].printHand();
						}
					}
					//Output highest call
					cout << endl << "      Highest call: ";
					highest.print();
					
					//Check if the highest call is there
					if(checkHighest()) {
						//Unsucessful
						cout << endl << "      The highest call is there! Player " << i + 1 << " has BS'd unsucessfully!" << endl;
						//Add a card to the player who BS'd
						players[i].cards++;
						//If they have more cards than the max
						if(players[i].cards > players[i].maxH) {
							//Eliminate them
							players[i].playing = false;
							cout << endl << "      Player " << i + 1 << " has been eliminated!!! " << endl;
							
							//If there is only one player left, end the game
							bool ending = false;
							for(int i = 0; i < numP; i++) {
								if(ending && players[i].playing) {
									ending = false;
									break;
								} else if(players[i].playing) {
									ending = true;
								}
							}
							if(ending) {
								endGame(i - 1 >= 0 ? i - 1 : numP - 1);
								playing = false;
							//If the game is not ending, output and pause
							} else {
								cout << endl << "      ";
								system("pause");
							}
						//If the player has not been eliminated, output and pause
						} else {
							starting = i;
							cout << endl << "      ";
							system("pause");
						}
						//Set the next starting player to the person who was BS'd
						starting = i - 1 >= 0 ? i - 1 : numP - 1;
					} else {
						//Find the index of the player who was sucessfully BS'd
						int playerIndex = i - 1 >= 0 ? i - 1 : numP - 1;
						cout << endl << "      The highest call is not there! Player " << i + 1 << " has BS'd sucessfully!" << endl;
						//Add a card to the player who was BS'd
						players[playerIndex].cards++;
						//If they have more cards than the max
						if(players[playerIndex].cards > players[playerIndex].maxH) {
							//Eliminate them
							players[playerIndex].playing = false;
							cout << endl << "      Player " << (i - 1 >= 0 ? i : numP) << " has been eliminated!!!" << endl;
							
							//If there is only one player left, end the game
							bool ending = false;
							for(int i = 0; i < numP; i++) {
								if(ending && players[i].playing) {
									ending = false;
									break;
								} else if(players[i].playing) {
									ending = true;
								}
							}
							if(ending) {
								endGame(i);
								playing = false;
							//If the game is not ending, output and pause
							} else {
								cout << endl << "      ";
								system("pause");
							}
						//If the player has not been eliminated, output and pause
						} else {
							cout << endl << "      ";
							system("pause");
						}
						//Set the starting player to the player who called BS
						starting = i;
					}
					
					//End the round -- cause the round loop to end
					round++;
					roundControl = false;
				
				//If the player did NOT call BS
				} else {
					//Set up temporary data
					int temp1, temp2;
					char temp3[20];
					selecting = true;
					
					do {
						//Switch on what type of hand they selected
						switch(selection) {
							//All single-card hand types
							case HIGH_CARD - 1:
							case PAIR - 1:
							case TRIPLE - 1:
							case QUAD - 1:
								//Input value of card within hand
								cout << endl << "      Enter value (1-13): ";
								cin >> temp1;
								cin.ignore(1000,'\n');
								//If the value is valid (1-13)
								if(temp1 > 0 && temp1 < 14) {
									//If the value is 1 (an ace), make it 14 so aces are high
									if(temp1 == 1) temp1 = 14;
									
									//If the call is valid: if the level of the hand is higher or the card is higher
									if((hand_type)selection > highest.lvl || (temp1 > highest.v1.getValue() && (hand_type)selection == highest.lvl)) {
										//Set the new highest hand value
										highest.v1.setValue((temp1 == 14 ? 1 : temp1),true);
										selecting = false;
										//If you called the highest hand of this type (one ace, two ace, etc), mark that it cannot be called again
										if(temp1 == 14) {
											offset = 1;
										} else {
											offset = 0;
										}
										//set the highest hand level
										highest.lvl = (hand_type)selection;
									//If value is not higher
									} else {
										cout << endl << "      Please enter a hand higher than the last call!" << endl;
									}
								//If card is not valid
								} else {
									cout << endl << "      Please enter a valid value (1-13)!" << endl;
								}
								break;
							//Two pairs:
							case TWO_PAIR - 1:
									//Input both pair values
									cout << endl  << "      Enter first value (1-13): ";
									cin >> temp1;
									cin.ignore(1000,'\n');
									cout << endl  << "      Enter second value (1-13): ";
									cin >> temp2;
									cin.ignore(1000,'\n');
									
									//If both cards are valid (1-13)
									if(temp1 > 0 && temp1 < 14 && temp2 > 0 && temp2 < 14) {
										//If the value is 1 (an ace), make it 14 so aces are high
										if(temp1 == 1) temp1 = 14;
										if(temp2 == 1) temp2 = 14;
										//If you input the same number for both
										if(temp1 == temp2) {
											cout << endl << "      Please enter two different values!" << endl;
										//If the hand is higher: if the level of the hand is higher or one of the pairs is higher than the other while the other
										//is also greater than or equal to the other respective pair. For example, 3 5 > 3 4, 5 7 > 4 3, 3 4 < 3 4, etc
										} else if((hand_type)selection > highest.lvl || ((min(temp1,temp2) >= min(highest.v1.getValue(),highest.v2.getValue()) && 
																			   		      max(temp1,temp2) >= max(highest.v1.getValue(),highest.v2.getValue()) &&
																					    !(min(temp1,temp2) == min(highest.v1.getValue(),highest.v2.getValue()) &&
																					      max(temp1,temp2) == max(highest.v1.getValue(),highest.v2.getValue()))) &&
																						  (hand_type)selection == highest.lvl)) {
											//Set the new highest hand value
											highest.v1.setValue((temp1 == 14 ? 1 : temp1),true);
											highest.v2.setValue((temp2 == 14 ? 1 : temp2),true);
											selecting = false;
											//If you called the highest hand of this type (one ace, two ace, etc), mark that it cannot be called again
											if((temp1 == 14 && temp2 == 13) || (temp1 == 13 && temp2 == 14)) {
												offset = 1;
											} else {
												offset = 0;
											}
											//Set the highest hand type
											highest.lvl = (hand_type)selection;
										//If hand is not higher
										} else {
											cout << "      Please enter a hand higher than the last call!" << endl;
										}
									//If cards are not valid
									} else {
										cout << endl << "      Please enter a valid value (1-13)!" << endl;
									}
								break;
							//Full hosue:
							case FULL_HOUSE - 1:
								//Input card values
								cout << endl  << "      Enter pair value (1-13): ";
								cin >> temp1;
								cin.ignore(1000,'\n');
								cout << endl  << "      Enter triple value (1-13): ";
								cin >> temp2;
								cin.ignore(1000,'\n');
											
								//If both cards are valid (1-13)		
								if(temp1 > 0 && temp1 < 14 && temp2 > 0 && temp2 < 14) {
									//If the value is 1 (an ace), make it 14 so aces are high
									if(temp1 == 1) temp1 = 14;
									if(temp2 == 1) temp2 = 14;
									//If you input the same number for both
									if(temp1 == temp2) {
										cout << endl << "      Please enter two different values!" << endl;
									//If the hand is higher: if the level fo the hand is higher or one of the sub-hands (pair or triple) is higher while the other is equal
									//to or higher the other respective sub hand
									} else if((hand_type)selection > highest.lvl || ((temp1 >= highest.v1.getValue() && 
																		   		      temp2 >= highest.v2.getValue() &&
																				    !(temp1 == highest.v1.getValue() &&
																				      temp2 == highest.v2.getValue())) &&
																					  (hand_type)selection == highest.lvl)) {
										//Set the new highest hand value
										highest.v1.setValue((temp1 == 14 ? 1 : temp1),true);
										highest.v2.setValue((temp2 == 14 ? 1 : temp2),true);
										selecting = false;
										//If you called the highest hand of this type (one ace, two ace, etc), mark that it cannot be called again
										if(temp2 == 14 && temp1 == 13) {
											offset = 1;
										} else {
											offset = 0;
										}
										//Set the highest hand type
										highest.lvl = (hand_type)selection;
									//If the hand is not higher
									} else {
										cout << "      Please enter a hand higher than the last call!" << endl;
									}
								//If the cards are not valid
								} else {
									cout << endl << "      Please enter a valid value (1-13)!" << endl;
								}
								break;
							//Straight flush:
							case STRAIGHT_FLUSH - 1:
								//Inptu suit
								cout << endl << "      Please enter the suit of your straight (hearts,diamonds,clubs,spades): ";
								cin >> temp3;
								cin.ignore(1000,'\n');
								//If suit is not valid
								if(!checkSuit(temp3)) {
									cout << endl << "      Please enter a valid value (hearts,diamonds,clubs,spades)!" << endl;
									//end switch statement
									break;	
								} else {
									//Set highest call suit
									strcpy(highest.suit,temp3);
								}
								//Continue to straight input, do not break switch statement
							case STRAIGHT - 1:
								//Input starting card of straight
								cout << endl << "      Please enter the lowest value of your straight (2-10): ";
								cin >> temp1;
								cin.ignore(1000,'\n');
								//If card is valid (2-10)
								if(temp1 > 1 && temp1 < 11) {
									//If hand is higher: if level is higher or the starting value of the suit or the straight starts at a higher card
									if((hand_type)selection > highest.lvl || (temp1 > highest.v1.getValue() && (hand_type)selection == highest.lvl)) {
										//Set the new highest hand value
										highest.v1.setValue(temp1,true);
										highest.v2.setValue(temp1 + 4 == 14 ? 1 : temp1 + 5,true);
										selecting = false;
										//If you called the highest hand of this type (one ace, two ace, etc), mark that it cannot be called again
										if(temp1 == 10) {
											offset = 1;
										}
										//Set the highest hand type
										highest.lvl = (hand_type)selection;
									//If the hand is not higher
									} else {
										cout << endl << "      Please enter a hand higher than the last call!" << endl;
									}
								//If the card was not valid
								} else {
									cout << endl << "      Please enter a valid value (2-10)!" << endl;
								}
								break;
						}
						//Re-do the sub hand input loop if the player did not enter a valid value
					} while(selecting);
					
					//End the player's turn
					cout << endl << "      End your turn: "; 
					system("pause");
				}
			}
		}
		}
	}
	
	//Output a closing message -- the program will end after this
	cout << endl << "      Thanks for playing!" << endl
		 << endl << "      ";
	system("pause");
}

//Check if a string is a valid suit
bool game::checkSuit(char* str) {
	//PUt string in lower case
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
	//Test string adn resturn results
	return strcmp(str,"hearts") == 0 ||
		   strcmp(str,"clubs") == 0 ||
		   strcmp(str,"diamonds") == 0 ||
		   strcmp(str,"spades") == 0;
}

//Ending screen
void game::endGame(int winner) {
	system("cls");
	//Display ending screen
	cout << endl << endl 
		 << "      =================================================" << endl
		 << endl << endl << endl << endl << endl
		 << "                Player " << winner + 1 << " has won the game!" << endl
		 << endl << endl << endl << endl << endl
		 << "      =================================================" << endl;
}














