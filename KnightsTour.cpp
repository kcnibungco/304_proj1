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

	for (int a = 0; a < width; a++)
	{
		Nexti = i + KTMOV1[a];
		Nextj = j + KTMOV2[a];


	if ((i >= 0 && i <= width) && (j >= 0 && j <= height) && cb[i][j] == 0)
		return true;				//If all conditions satisfied return true
	return false;					//Otherwise return false
}

bool tour(int cb[width][height], int i, int j, int KTMOV1, int KTMOV2, int M)
{
	
	return true;
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

	i = 0;	//starting x value
	j = 0;	// starting y value

	//i = rand() % width;	//starting x value
	//j = rand() % width;	// starting y value

	cb[i][j] = 1;	//Set the starting position to 1

	int KTMOV1[width] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//possible move options
	int KTMOV2[height] = { 1, 2, 2, 1, -1, -2, -2, -1 };//for the knight


	cout << "The Knights initial position is (" << i << "," << j << ").\n";

	if (tour(cb, i, j, KTMOV1[width], KTMOV2[height], 0) == false)	//Recursive function and
	{													//check if tour is true
		cout << "The tour does not exist.\n";
	}

	else
	{
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