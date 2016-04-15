//===================================================================================
// Project     : KnightsTourProject.cpp
// Description : Program mimics the movement of the knight on a chessboard
// Company     : Cal Poly Pomona
// Course      : ECE 304
// Name		   : David Moreno and Kim Nibungco
//===================================================================================
#include "stdafx.h"
#include <iostream>
#include "KnightsTour.h"

#define SIZE 8

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

bool tour(int cb[SIZE][SIZE], int i, int j, int KTMOV1, int KTMOV2, int M)
{

}

void KnightsTour()
{
	int cb[SIZE][SIZE];				//matrix for chessboard 8 X 8
	int i, j;							//position of the knight

	for (int x = 0; x < SIZE; x++)		//for loop to fill the 8 X 8 with 0's
	{
		for (int y = 0; y < SIZE; y++)
		{
			cb[x][y] = 0;
		}
	}

	i = 0;	//starting x value
	j = 0;	// starting y value

	cb[i][j] = 1;	//Set the starting position to 1

	int KTMOV1[SIZE] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//possible move options
	int KTMOV2[SIZE] = { 1, 2, 2, 1, -1, -2, -2, -1 };//for the knight


	cout << "The Knights initial position is (" << i << "," << j << ").\n";

	if (tour(cb, i, j, KTMOV1, KTMOV2, 0) == false)	//Recursive function and
	{													//check if tour is true
		cout << "The tour does not exist.\n";
	}

	else
	{
		for (int x = 0; x < SIZE; x++)		//print out the chessboard matrix
		{
			for (int y = 0; y < SIZE; y++)
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