#include "mainBattleship.h"
#include <iostream>
#include <string>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

bool HasLost(char board[100])
{
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (board[i] == '>')
		{
			count++;
		}
	}

	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char* PlaceShips(char board[100], int shipCount)
{
	srand(time(0));
	char* P1 = board;

	for (int i = 0; i < shipCount; i++)
	{
		int shipPlacement = rand() % 95 + 1;
		for (int j = 0; j < 5; j++)
		{
			board[shipPlacement + j] = '>';
		}
	}

	return P1;
}

void DisplayBoard(char board[100])
{
	cout << "[ ][1][2][3][4][5][6][7][8][9][10]" << endl;
    for (int i = 0; i < 10; i++)
    {
		if (i == 0) cout << "[" << "A" << "]";
		else if (i == 1) cout << "[" << "B" << "]";
		else if (i == 2) cout << "[" << "C" << "]";
		else if (i == 3) cout << "[" << "D" << "]";
		else if (i == 4) cout << "[" << "E" << "]";
		else if (i == 5) cout << "[" << "F" << "]";
		else if (i == 6) cout << "[" << "G" << "]";
		else if (i == 7) cout << "[" << "H" << "]";
		else if (i == 8) cout << "[" << "I" << "]";
		else if (i == 9) cout << "[" << "J" << "]";
        for (int j = 0; j < 10; j++)
        {
            cout << "[" << board[(i * 10) + j] << "]";
        }
        cout << endl;
    }
}

int getLetterNumber(char letter) {
	if (letter == 'a') return 0;
	else if (letter == 'b') return 1;
	else if (letter == 'c') return 2;
	else if (letter == 'd') return 3;
	else if (letter == 'e') return 4;
	else if (letter == 'f') return 5;
	else if (letter == 'g') return 6;
	else if (letter == 'h') return 7;
	else if (letter == 'i') return 8;
	else if (letter == 'j') return 9;
}

int getPositionInArray(string cords)
{
	int result = 0;

	int x = getLetterNumber(cords[0]) * 10;
	int y = (int)(cords[1]) - 1;

	result = x + y - 48;

	return result;
}

int main()
{
	int currentPlayer = 1;

	char P1Board[100] = {};
	char P2Board[100] = {};
	char P1BoardDisplay[100] = {};
	char P2BoardDisplay[100] = {};

	bool isOver = false;

	for (int i = 0; i < 100; i++)
	{
		P1Board[i] = '?';
		P2Board[i] = '?';
		P1BoardDisplay[i] = '=';
		P2BoardDisplay[i] = '=';
	}

	char* p1temp = PlaceShips(P1Board, 5);
	char* p2temp = PlaceShips(P1Board, 5);

	for (int i = 0; i < 100; i++)
	{
		P1Board[i] = p1temp[i];
		P2Board[i] = p2temp[i];
	}

	DisplayBoard(P1Board);

	cout << "Welcome to Battleship!" << endl;
	cout << "Your ships will be randomly placed on your battlefield\n" << endl;

	while(!isOver)
	{
		if (currentPlayer == 1)
		{
			cout << "Player One Enter a Grid Location To Attack!\n" << endl;
			DisplayBoard(P2BoardDisplay);
			string input = "";
			cin >> input;
			cout << "\n Player One Attacked " << input << " loction on the enemy grid" << endl;

			if (P2Board[getPositionInArray(input)] == '>')
			{
				cout << "Attack Hit!\n";
				P2BoardDisplay[getPositionInArray(input)] = 'X';
			}
			else {
				cout << "Attack Miss!\n";
				P2BoardDisplay[getPositionInArray(input)] = 'O';
				DisplayBoard(P2BoardDisplay);
			}

			if (HasLost(P2Board)) {
				cout << "Player One Wins!\n" << endl;
				isOver = true;
				break;
			}

			currentPlayer = 2;
		}

		if (currentPlayer == 2)
		{
			cout << "Player Two Enter a Grid Location To Attack!\n" << endl;
			DisplayBoard(P1BoardDisplay);
			string input = "";
			cin >> input;
			cout << "\n Player Two Attacked " << input << " loction on the enemy grid" << endl;

			if (P1Board[getPositionInArray(input)] == '>')
			{
				cout << "Attack Hit!\n";
				P1BoardDisplay[getPositionInArray(input)] = 'X';
			}
			else {
				cout << "Attack Miss!\n";
				P1BoardDisplay[getPositionInArray(input)] = 'O';
				DisplayBoard(P1BoardDisplay);
			}

			if (HasLost(P1Board)) {
				cout << "Player Two Wins!\n" << endl;
				isOver = true;
				break;
			}

			currentPlayer = 1;
		}
	}

	return 0;
}

//2 Players
//10 x 10 grid per player
//Simplified Ship Sizes : Only 5x 1 sized ships
//Players take alternating turns
//Coordinates given in the form g7, a2, d2 etc...
//consider using the numeric value of chars!: )
//can be simplified at first with two inputs :
//first: int x
//then : int y
//Feedback "Hit" or "Miss"
//Win Condition : All enemy ships have been sunk