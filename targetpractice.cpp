#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	/* SETUP BEGIN */

	int xCoord = 0;
	int yCoord = 0;
	const int LENGTH = 20;
	const int HEIGHT = 20;
	int targetCounter = 0;
	int turn = 1;

	char map[LENGTH][HEIGHT];
	int i = 0;
	int j = 0;

	enum userCommands { MAP, ATTACK, QUIT };
	userCommands state = MAP;
	char command = '-';


	srand(time(NULL));
	// map creation
	for (i = 0; i < LENGTH; i++) {					
		for (j = 0; j < HEIGHT; j++) {
			int random = rand() % 100;
			if ((i == random) || (j == random)){
				map[i][j] = 'X';
				targetCounter++;
			}
			else {
				map[i][j] = '-';
			}
		}
	}
	
	/* SETUP END */
	
	cout << "Welcome to Target Practice!" << endl << "The goal is to hit all the targets in the least amount of time possible."
		 << endl << "You can access the map as needed." << endl << endl;

	while (state != QUIT && targetCounter > 0){
		cout << "Turn: " << turn << endl;
		cout << "User commands: m (see map), a (attack), q (quit)" << endl << endl;
		cin >> command;

		switch (command) {
		case 'm':
			state = MAP;
			for (i = 0; i < LENGTH; i++){								// prints the updated map
				for (j = 0; j < HEIGHT; j++){
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			turn++;
			break;
		case 'a':
			state = ATTACK;

			cout << "Targets left: " << targetCounter << endl;
			// cout << << endl;
			while ((cout << "Please input the x-coordinate: (0-19) ") && (!(cin >> xCoord) || xCoord < 0 || xCoord > 19)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			while ((cout << "Please input the y-coordinate: (0-19) ") && (!(cin >> yCoord) || yCoord < 0 || yCoord > 19)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (map[yCoord][xCoord] == 'X'){
				cout << "HIT!" << endl << endl;
				map[yCoord][xCoord] = '\'';
				targetCounter--;
			}
			else {
				cout << "Miss..." << endl << endl;
			}
			turn++; 

			break;
		case 'q':
			state = QUIT;
			break;
		default:
			cout << "Invalid command. ";
			break;
		}

	}

	if (targetCounter == 0) {
		cout << "Game over! You win!" << endl;
	}
	return 0;
}

