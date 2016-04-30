//===================================================================================
// Project     : KnightsTourProject.cpp
// Description : Program mimics the movement of the knight on a chessboard
// Company     : Cal Poly Pomona
// Course      : ECE 304
// Name		   : David Moreno and Kim Nibungco
//===================================================================================
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "KnightsTour.h"

#define width 8
#define height 8

using namespace std;

//===================================================================================
// Name         : Knights Tour
// Description  : This program will allow a Knight to move to every space on a 
//					chessboard once and only once.
// Parameters   : Chessboard 8X8 Standard Size
// Global Data  : N = 8, height and width of chessboard
// Return Value : <None>
//===================================================================================

//===================================================================================
// FUNCTIONS
//===================================================================================

bool possibilitychecker(int Nexti, int Nextj, int cb[width][height])
{									//Checks validity of the next move
	int i = Nexti;					//Next i value
	int j = Nextj;					//Next j value

	if ((Nexti >= 0 && Nexti < width) && (Nextj >= 0 && Nextj < height) && cb[i][j] == 0)
		{
			return true;	//checks if the next move is valid
		}					//if it is return true
	return false;				//otherwise return false
}

bool tour(int cb[width][height], int i, int j, int KTMOV1[], int KTMOV2[], int M)
{
	int Nexti, Nextj;
		if (M == width * height)
		{
			return true;	//The tour has finished go back to the knightstour function
		}

	for (int a = 0; a < width; a++)
	{
		Nexti = i + KTMOV1[a];	//find the next move
		Nextj = j + KTMOV2[a];

		if (possibilitychecker(Nexti, Nextj, cb)) {
			// if the move is possible
			// increment the move count and store it in tour matrix
			cb[Nexti][Nextj] = M + 1;
			if (tour(cb, Nexti, Nextj, KTMOV1, KTMOV2, M + 1) == true)
			{
				return true;
			}
			else {
				//if the move was invalid, try out other possiblities 
				cb[Nexti][Nextj] = 0;
			}
		}
	}
	return false;
}

void KnightsTour()
{
	int cb[width][height];				//matrix for chessboard 8 X 8
	int i, j;							//position of the knight

	for (int x = 0; x < width; x++)		//for loop to fill the 8 X 8 with 0's
	{
		for (int y = 0; y < height; y++)
		{
			cb[x][y] = 0;
		}
	}

	i = 5;	//starting x value
	j = 5;	// starting y value

			//i = rand() % width;	//starting x value
			//j = rand() % width;	// starting y value

	cb[i][j] = 1;	//Set the starting position to 1

	int KTMOV1[width] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//possible move options
	int KTMOV2[height] = { 1, 2, 2, 1, -1, -2, -2, -1 };//for the knight


	cout << "The Knights initial position is (" << i << "," << j << ").\n";

	if (tour(cb, i, j, KTMOV1, KTMOV2, 1) == false)	//Recursive function and
	{													//check if tour is true
		cout << "The tour does not exist.\n";
	}

	else
	{
		cout << "The tour exists:\n";
		for (int x = 0; x < width; x++)		//print out the chessboard matrix
		{
			for (int y = 0; y < height; y++)
			{
				cout << cb[x][y] << "\t";
			}

			cout << "\n";
		}
	}
}

//===================================================================================
//MAIN
//===================================================================================

int main() {

	KnightsTour();					//Call the KnightsTour Function
	cout << endl;
	return 0;
}