// DiceRoll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int roll();
void displayWin(long int numOfWins, long int numOfLosses, long int numOfRounds, long int numOfSpecial); //parameters included; used to keep track of wins and losses for display;
void displayLoss(long int numOfLosses, long int numOfWins, long int numOfRounds, long int numOfSpecial);;
void quit(long int numOfWins, long int numOfLosses, long int numOfRounds, long int numOfSpecial); //method to end game;
int main()
{
	int seed; //seed to be used for random number generator;
	char character = 'r'; //character input for dice roll;
	int total = 0; // total of dice rolls;
	int dice1 = 0;//first dice roll;
	int dice2 = 0; //second dice roll;
	long int numOfWins = 0; //number of wins recorded;
	long int numOfLosses = 0; //number of losses recorded;
	int target = 0; //target for second round;
	long int numOfRounds = 0;
	long int numOfSpecial = 0;
	cout << "Welcome to the Dice Roll Challenge.  Attempt to roll the dice against one of the toughest random number challenges there is!" << endl;
	system("PAUSE");
	cout << "Enter a number: " << endl;
	cin >> seed;
	if (seed <= 0) {
		srand(time(NULL)); //use system time as seed if([cin << int entered] <= 0])
		cout << seed << " is the seed used.  This will be reset to the current time." << endl;
	}
	else {
		srand(seed); //use seed if(int entered > 0;)
		cout << seed << " is the seed used.  Seed saved." << endl;
	}
	while (character == 'r') { //while(character entetred == 'r') {
		cout << "Enter r to roll, or q to stop." << endl;
		cin >> character; //enter a character;
		if (character == 'r') { //if(character entered == 'r') {
			dice1 = roll(); //roll dice; save roll to first die;
			cout << "The first die roll is: " << dice1 << endl;
			total = total + dice1; //add dice roll to total;
			dice1 = 0;
			dice2 = roll(); //roll dice again; save roll to second die; }
			cout << "The second die roll is " << dice2 << endl;
			total = total + dice2;
			dice2 = 0;
		}
		else if (character == 'q') { //else if (character entered == 'q') {
			quit(numOfWins, numOfLosses, numOfRounds, numOfSpecial); //quit;
			system("PAUSE");
			return 0;
		}
		if (total == 7 || total == target) {//if(total == 7) {
			numOfWins++;
			numOfRounds++;
			displayWin(numOfWins, numOfLosses, numOfRounds, numOfSpecial); // player wins!;  display current results; }
		}
		else if (total == 2 ^ total == 3 ^ total == 12) { //else if(total of dice rolls == 2 XOR 3 XOR 12) {
			numOfLosses++;
			numOfRounds++;
			displayLoss(numOfLosses, numOfWins, numOfRounds, numOfSpecial); //player loses...; display current results; }
		}
		else if (total == 4 ^ total == 5 ^ total == 6 ^ total == 8 ^ total == 9 ^ total == 10) { //else if(total == 5 XOR 6 XOR 8 XOR 9 XOR 10) {
			target = total;
			total = 0;
			cout << "You rolled a special value!  Roll it again to win." << endl; //special value rolled!;
				
				while (total != target) { //continue to roll until total == target value;
					cout << "Enter r to roll, or q to stop" << endl;
					cin >> character;
					if (character == 'r') {
						dice1 = roll();
						cout << "The first die roll is " << dice1 << endl;
						total = total + dice1;
						dice1 = 0;
						dice2 = roll();
						cout << "The second die roll is " << dice2 << endl;
						total += dice2;
						dice2 = 0;
					}
					else if (character == 'q') {
						quit(numOfWins, numOfLosses, numOfRounds, numOfSpecial);
						system("PAUSE");
						return 0;
					}
					if (total == 7) {
						numOfLosses++;
						numOfRounds++;
						numOfSpecial++;
						displayLoss(numOfLosses, numOfWins, numOfRounds, numOfSpecial);
						break;
					}
					if (total == target) {
						numOfWins++;
						numOfRounds++;
						numOfSpecial++;
						displayWin(numOfWins, numOfLosses, numOfRounds, numOfSpecial);
						break;
					}
					total = 0;

					
				}
				
		}
		total = 0;
	}
	return 0;
}


	void displayWin(long int numOfWins, long int numOfLosses, long int numOfRounds, long int numOfSpecial) { //FAULTY: Not recording wins properly;
		cout << "Congratulations!  You win!" << endl;
		cout << "---------------" << endl;
		cout << "current wins = " << numOfWins << ".  current losses = " << numOfLosses << ". Number of Rounds = " << numOfRounds << ".  Number of Special rounds = " << numOfSpecial << endl;
		return;
	}
	void displayLoss(long int numOfLosses, long int numOfWins, long int numOfRounds, long int numOfSpecial) { //FAULTY: Not recording losses properly;
		cout << "Sorry... You lose." << endl;
		cout << "----------------" << endl;
		cout << "current wins = " << numOfWins << ".  current losses = " << numOfLosses << ". Number of Rounds = " << numOfRounds << ".  Number of Special rounds = " << numOfSpecial << endl;
		return;
	}
	void quit(long int numOfWins, long int numOfLosses, long int numOfRounds, long int numOfSpecial) {
		int numOfRolls = 0;
		int nextRoll = 0;
		long int numOf1 = 0;
		long int numOf2 = 0;
		long int numOf3 = 0;
		long int numOf4 = 0;
		long int numOf5 = 0;
		long int numOf6 = 0;
		cout << "The final results are: number of wins = " << numOfWins << ", number of losses = " << numOfLosses << ", number of Rounds = " << numOfRounds << ", number of Special rounds = " << numOfSpecial << endl;
		while (numOfRolls < 60000) {
			nextRoll = roll();
			switch (nextRoll) {
			case 1: numOf1++; break;
			case 2: numOf2++; break;
			case 3: numOf3++; break;
			case 4: numOf4++; break;
			case 5: numOf5++; break;
			case 6: numOf6++; break;
			}
			numOfRolls++;
		}
		cout << "Number of ones rolled is " << numOf1 << endl;
		cout << "Number of twos rolled is " << numOf2 << endl;
		cout << "Number of threes rolled is " << numOf3 << endl;
		cout << "Number of fours rolled is " << numOf4 << endl;
		cout << "Number of fives rolled is " << numOf5 << endl;
		cout << "Number of sixes rolled is " << numOf6 << endl;
		return;


	}
	int roll() {
		int dice = 1 + (rand()) % 6;
		return dice;
	}
